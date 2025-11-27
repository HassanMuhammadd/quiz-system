#include "Teacher.h"

#include <iostream>

vector<Teacher*> Teacher::allTeachers;

Teacher::Teacher(string name, string email, string password)
	: User(nextId++, User::TEACHER, name, email, password) {}

vector<Teacher*>& Teacher::getAllTeachers() { return allTeachers; }

int Teacher::getId() { return id; }

string Teacher::getName() { return name; }

vector<Quiz*>& Teacher::getQuizzes() { return quizzes; }

Quiz* Teacher::createQuiz(int timeLimitInMinutes, string title, int year, int month, int day, int hour, int minute) {
	Quiz *quiz = new Quiz(timeLimitInMinutes, title, year, month, day, hour, minute);
	quizzes.push_back(quiz);
	return quiz;
}

Quiz* Teacher::editQuiz(int id, int timeLimitInMinutes, string title, int year, int month, int day, int hour, int minute) {
	for (Quiz *quiz : quizzes) {
		if (quiz->getId() == id) {
			quiz->setTimeLimitInMinutes(timeLimitInMinutes);
			quiz->setTitle(title);
			quiz->publishQuiz(year, month, day, hour, minute);
			return quiz;
		}
	}
	cout << "\n===Quiz not found===\n";
	return nullptr;
}

bool Teacher::deleteQuiz(int id) {
	for (auto it = quizzes.begin(); it != quizzes.end(); ++it) {
		if ((*it)->getId() == id) {
			quizzes.erase(it);
			delete *it;
			return true;
		}
	}
	cout << "\n===Quiz not found===\n";
	return false;
}

void Teacher::viewStudentsResults(int quizId) {
	vector<Result*> results = Result::findQuizResults(quizId);
	for (Result *result : results) {
		result->displayResult();
		cout << "\n==========\n";
	}
}

void Teacher::displayMenu() {
	int choice;
	bool finished = false;
	while (true) {
		cout << "\n===Welcome " << this->getName() << "===\n";
		cout << "1. Create Quiz\n";
		cout << "2. Edit Quiz\n";
		cout << "3. Delete Quiz\n";
		cout << "4. View Students Results\n";
		cout << "5. Logout\n";
		cout << "Enter your choice: ";

		cin >> choice;
		switch (choice) {
			case 1: {
				prepareCreateQuiz();
				break;
			}
			case 2: {
				prepareEditQuiz();
				break;
			}
			case 3: {
				prepareDeleteQuiz();
				break;
			}
			case 4: {
				prepareViewStudentsResults();
				break;
			}
			case 5: {
				finished = true;
				break;
			}
			default: {
				cout << "\n===Invalid choice===\n";
				break;
			}
		}
		if( finished ) break;
	}
}

void Teacher::prepareCreateQuiz() {
	int timeLimitInMinutes;
	string title;
	cout << "Enter time limit in minutes: ";
	cin >> timeLimitInMinutes;
	cout << "Enter title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter publish time (year month day hour minute): ";
	int year, month, day, hour, minute;
	cin >> year >> month >> day >> hour >> minute;

	Quiz* quiz = createQuiz(timeLimitInMinutes, title, year, month, day, hour, minute);
	addQuestions(quiz->getId());
}

void Teacher::prepareEditQuiz() {
	displayTeacherQuizzes();
	int choice;
	int id;
	cout << "Enter Quiz ID: ";
	cin >> id;
	cout << "\n1. Update general info\n2. Add question\n";
	cin >> choice;
	if(choice == 1) {
		int timeLimitInMinutes;
		string title;

		cout << "Enter time limit in minutes: ";
		cin >> timeLimitInMinutes;

		cout << "Enter title: ";
		cin.ignore();
		getline(cin, title);

		cout << "Enter publish time (year month day hour minute): ";
		int year, month, day, hour, minute;
		cin >> year >> month >> day >> hour >> minute;

		editQuiz(id, timeLimitInMinutes, title, year, month, day, hour, minute);
		}
		else if(choice == 2) {
			addQuestions(id);
		} else {
			cout << "\n===Invalid choice===\n";
		}
}

void Teacher::prepareDeleteQuiz() {
	int id;
	cout << "Enter id: ";
	cin >> id;
	deleteQuiz(id);
}

void Teacher::prepareViewStudentsResults() {
	int quizId;
	cout << "Enter quiz id: ";
	cin >> quizId;
	viewStudentsResults(quizId);
}

void Teacher::displayTeacherQuizzes() {
	for (Quiz *quiz : quizzes) {
		quiz->displayQuiz();
		cout << "\n==========\n";
	}
}

void Teacher::addQuestions(int id) {
	Quiz* quiz = Quiz::findQuiz(id);
	if(quiz == nullptr) {
		cout << "\n===Quiz not found===\n";
		return;
	}
	string text;
	float score;
	do {
		cout << "Enter question text (-1 to stop adding questions): ";
		cin.ignore();
		getline(cin, text);
		if(text == "1") break;
		cout << "Enter score: ";
		cin >> score;
		Question *question = quiz->addQuestion(text, score);
		string optionText;
		bool isCorrect;
		do {
			cout << "Enter option (-1 to stop adding options): ";
			cin.ignore();
			getline(cin, optionText);

			if(optionText == "-1") break;

			cout << "Enter is correct (true/false): ";
			cin >> isCorrect;

			question->addOption(optionText, isCorrect);
		} while (optionText != "-1");
	} while (text != "1");
}