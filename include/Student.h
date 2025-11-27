#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Quiz.h"
#include "Result.h"

#include <vector>

class Student : public User {
	inline static int nextId = 1;
	public:

	// self registering instance list
	static vector<Student*> allStudents;

	Student(string name, string email, string password);

	int getId();
	string getName();

	bool getQuizzes();
	void startQuiz();
	vector<string> solveQuizQuestions(Quiz* quiz);
	void submitQuiz(int quizId, vector<string> answers);

	void viewResultsInAQuiz(int quizId);
	void viewResultsInAllQuizzes();

	void displayMenu() override;


	static std::vector<Student*>& getAllStudents();
};

#endif // STUDENT_H
