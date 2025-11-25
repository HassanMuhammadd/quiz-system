#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"

#include <string>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
using namespace std::chrono;

class Quiz {
	int id;
	int timeLimitInMinutes;
	string title;
	system_clock::time_point activeAt;
	vector<Question*> questions;

	inline static int nextId = 1;

	public:
	static vector<Quiz*> allQuizzes;

	// Constructor accepting date/time components from user input
	Quiz(int timeLimitInMinutes, string title, int year, int month, int day, int hour = 0, int minute = 0);


	system_clock::time_point getActiveAt();
	int getId();

	static vector<Quiz*>& getAllQuizzes();

	void publishQuiz(Quiz quiz);
	void unpublishQuiz(int id);

	Quiz& addQuestion(string text, float points);
	void removeQuestion(int id);
	vector<Question*> getQuestions();

};

#endif // QUIZ_H