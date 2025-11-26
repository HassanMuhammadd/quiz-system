#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Quiz.h"

#include <vector>

class Student : public User {
	vector<Quiz> quizzes;


	public:
	static vector<Student*> allStudents;

	Student(string name, string email, string password);

	//vector<Quiz> getQuizzes();
	//void addQuiz(Quiz quiz);
	void startQuiz(Quiz quiz);
	void submitQuiz(Quiz quiz);
	void viewResults(int quizId);

	static std::vector<Student*>& getAllStudents();
};

#endif // STUDENT_H
