#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Quiz.h"

#include <vector>

class Teacher : public User {


	public:
	static vector<Teacher*> allTeachers;

	Teacher(string name, string email, string password);

	void createQuiz(Quiz quiz);
	void editQuiz(Quiz quiz);
	void deleteQuiz(int id);
	void viewStudentResults(int quizId, int studentId);

	static vector<Teacher*>& getAllTeachers();
};

#endif // TEACHER_H
