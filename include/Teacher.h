#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Quiz.h"
#include "Result.h"

#include <vector>

class Teacher : public User {
	inline static int nextId = 1;
	vector<Quiz*> quizzes;

	public:
	static vector<Teacher*> allTeachers;

	Teacher(string name, string email, string password);

	int getId();
	string getName();
	vector<Quiz*>& getQuizzes();

	Quiz& createQuiz(int timeLimitInMinutes, string title);
	Quiz* editQuiz(int id, int timeLimitInMinutes, string title);
	bool deleteQuiz(int id);
	void viewStudentsResults(int quizId);


	static vector<Teacher*>& getAllTeachers();
};

#endif // TEACHER_H
