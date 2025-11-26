#include "Teacher.h"

#include <iostream>

vector<Teacher*> Teacher::allTeachers;

Teacher::Teacher(string name, string email, string password)
	: User(nextId++, User::TEACHER, name, email, password) {}

vector<Teacher*>& Teacher::getAllTeachers() { return allTeachers; }

int Teacher::getId() { return id; }

string Teacher::getName() { return name; }

vector<Quiz*>& Teacher::getQuizzes() { return quizzes; }

Quiz& Teacher::createQuiz(int timeLimitInMinutes, string title) {
	Quiz *quiz = new Quiz(timeLimitInMinutes, title);
	quizzes.push_back(quiz);
	return *quiz;
}

Quiz* Teacher::editQuiz(int id, int timeLimitInMinutes, string title) {
	for (Quiz *quiz : quizzes) {
		if (quiz->getId() == id) {
			quiz->setTimeLimitInMinutes(timeLimitInMinutes);
			quiz->setTitle(title);
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
