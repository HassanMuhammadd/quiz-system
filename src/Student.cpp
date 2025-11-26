#include "Student.h"

#include <iostream>

vector<Student*> Student::allStudents;

Student::Student(string name, string email, string password)
	: User(nextId++, User::STUDENT, name, email, password) {}

vector<Student*>& Student::getAllStudents() { return allStudents; }

int Student::getId() { return id; }
string Student::getName() { return name; }

void Student::viewResultsInAllQuizzes() {
	for (Result *result : Result::allResults) {
		if (result->getStudentId() == id) {
			result->displayResult();
			cout << "\n==========\n";
		}
	}
}

void Student::viewResultsInAQuiz(int quizId) {
	vector<Result*> results = Result::findStudentResults(id);
	for (Result *result : results) {
		if (result->getQuizId() == quizId) {
			result->displayResult();
			return;
		}
	}
	cout << "\n===You have not taken this quiz===\n";
}

// Display only the puublished quizzes that are not taken by the student
void Student::getQuizzes() {
	for (Quiz *quiz : Quiz::allQuizzes) {
		Result* result = Result::findResult(id, quiz->getId());
		if (quiz->getPublishAt() <= system_clock::now() && result == nullptr) {
			quiz->displayQuiz();
			cout << "\n==========\n";
		}
	}
}


void Student::startQuiz() {
	getQuizzes();
	int quizId;
	cout << "Enter the quiz ID you want to take: ";
	cin >> quizId;

	Quiz *quiz = Quiz::findQuiz(quizId);

	if (quiz == nullptr) {
		return;
	}
	if (quiz->getPublishAt() > system_clock::now()) {
		cout << "\n===Quiz is not published yet===\n";
		return;
	}
	// display questions one by one and store the user's answers
	vector<string> answers;
	for (Question *question : quiz->getQuestions()) {

		cout << "\n==========\n";
		cout << question->getText() << endl;
		vector<string> options = question->getOptions();
		for (int i = 0; i < options.size(); i++) {
			cout << i + 1 << ". " << options[i] << endl;
		}

		int answer;
		while(true) {
			cout << "Enter your choice: ";
			cin >> answer;
			if(answer < 1 || answer > options.size()) {
				cout << "Invalid choice, try again\n";
				continue;
			} else {
				break;
			}
		}
		answers.push_back(options[answer - 1]);
	}
	submitQuiz(quizId, answers);
}

// create a result object
// calculate score
// save result
void Student::submitQuiz(int quizId, vector<string> answers) {
	Result *result = new Result(quizId, id, system_clock::now());
	vector<Question*>& correctAnswers = Quiz::findQuiz(quizId)->getQuestions();
	pair<float, float> score = result->calculateScore(correctAnswers, answers);
	cout << "Score: " << score.first << "/" << score.second << endl;
	Result::allResults.push_back(result);
}