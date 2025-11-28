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

	Quiz* createQuiz(int timeLimitInMinutes, string title, int year, int month, int day, int hour, int minute);
	Quiz* editQuiz(int id, int timeLimitInMinutes, string title, int year, int month, int day, int hour, int minute);
	bool deleteQuiz(int id);
	bool deleteQuestion(int quizId, int questionNumber);

	void viewStudentsResults(int quizId);
	void displayTeacherQuizzes();
	void addQuestions(int id);

	void displayMenu() override;

	void prepareCreateQuiz();
	void prepareEditQuiz();
	void prepareDeleteQuiz();
	void prepareViewStudentsResults();
	void prepareDeleteQuestion(int id);

	static vector<Teacher*>& getAllTeachers();
};

#endif // TEACHER_H
