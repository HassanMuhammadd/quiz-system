#include "Student.h"

#include <iostream>

vector<Student*> Student::allStudents;

Student::Student(string name, string email, string password)
	: User(nextId++, User::STUDENT, name, email, password) {}

vector<Student*>& Student::getAllStudents() { return allStudents; }

int Student::getId() { return id; }
string Student::getName() { return name; }

void Student::viewResultsInAllQuizzes() {
	bool empty = true;
	for (Result *result : Result::allResults) {
		if (result->getStudentId() == id) {
			empty = false;
			result->displayResult();
			cout << "\n==========\n";
		}
	}
	if (empty) {
		cout << "\n===You have not taken any quizzes===\n";
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
bool Student::getQuizzes() {
	bool empty = true;
	for (Quiz *quiz : Quiz::allQuizzes) {
		// if its null, then the user did not solve it
		Result* result = Result::findResult(id, quiz->getId());
		if (quiz->getPublishAt() <= system_clock::now() && result == nullptr) {
			empty = false;
			quiz->displayQuiz();
			cout << "\n==========\n";
		}
	}
	return empty;
}


void Student::startQuiz() {
	bool empty = getQuizzes();
	if (empty) {
		cout << "\n===There are no available quizzes===\n";
		return;
	}

	int quizId;
	cout << "Enter the quiz ID you want to take: ";
	cin >> quizId;

	Quiz *quiz = Quiz::findQuiz(quizId);

	if (quiz == nullptr) {
		cout << "\n===Quiz not found===\n";
		return;
	}

	if (quiz->getPublishAt() > system_clock::now()) {
		cout << "\n===Quiz is not published yet===\n";
		return;
	}

	vector<string> answers = solveQuizQuestions(quiz);
	submitQuiz(quizId, answers);
}

vector<string> Student::solveQuizQuestions(Quiz* quiz) {
	// display questions one by one and store the user's answers
	vector<string> answers;

	// Start timing the quiz
	auto startTime = system_clock::now();
	int timeLimitMinutes = quiz->getTimeLimitInMinutes();

	vector<Question*> questions = quiz->getQuestions();
	for (int i = 0; i < questions.size(); i++) {
		Question *question = questions[i];
		// Check if time limit has been exceeded before each question
		auto currentTime = system_clock::now();
		auto elapsedMinutes = duration_cast<minutes>(currentTime - startTime).count();

		if (elapsedMinutes >= timeLimitMinutes) {
			cout << "\n==========\n";
			cout << "TIME'S UP! The quiz time limit of " << timeLimitMinutes << " minutes has been reached.\n";
			cout << "Submitting your answers for the questions you completed\n";
			break;
		}

		int remainingMinutes = timeLimitMinutes - elapsedMinutes;

		cout << "\n========== (" << remainingMinutes << " min left)\n";
		cout << question->getText() << endl;
		vector<string> options = question->getOptions();
		for (int i = 0; i < options.size(); i++) {
			cout << i + 1 << ". " << options[i] << endl;
		}

		int answer;
		cout << "Enter your choice: ";
		cin >> answer;
		if(answer < 1 || answer > options.size()) {
			cout << "Invalid choice, try again\n";
			i--;
		} else {
			answers.push_back(options[answer - 1]);
		}

	}
	return answers;
}

// create a result object
// calculate score
// save result
void Student::submitQuiz(int quizId, vector<string> answers) {
	Result *result = new Result(quizId, id, system_clock::now());

	vector<Question*>& correctAnswers = Quiz::findQuiz(quizId)->getQuestions();
	pair<float, float> score = result->calculateScore(correctAnswers, answers);

	cout << "\n===== Quiz Finished =====\n";
	cout << "Score: " << score.first << "/" << score.second << endl;
	Result::allResults.push_back(result);
}

void Student::displayMenu() {
	int choice;
	bool finished = false;
	while (true) {
		cout << "\n===Welcome " << this->getName() << "===\n";
		cout << "1. Start Quiz\n";
		cout << "2. View Results in All Quizzes\n";
		cout << "3. View Results in a Quiz\n";
		cout << "4. Logout\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				startQuiz();
				break;
			}
			case 2: {
				viewResultsInAllQuizzes();
				break;
			}
			case 3: {
				int quizId;
				cout << "Enter the quiz ID you want to view results in: ";
				cin >> quizId;
				viewResultsInAQuiz(quizId);
				break;
			}
			case 4: {
				finished = true;
				break;
			}
			default: {
				cout << "\n===Invalid choice===\n";
				break;
			}
		}
		if (finished) break;
	}
}
