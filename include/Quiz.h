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
	system_clock::time_point publishAt;
	vector<Question*> questions;

	inline static int nextId = 1;

	public:
	static vector<Quiz*> allQuizzes;

	// Constructor accepting date/time components from user input
	Quiz(int timeLimitInMinutes, string title);


	system_clock::time_point getPublishAt();
	int getId();

	static vector<Quiz*>& getAllQuizzes();

	void publishQuiz(int year, int month, int day, int hour, int minute);
	void unpublishQuiz(int id);

	Quiz& addQuestion(string text, float points);
	void removeQuestion(int id);
	vector<Question*> getQuestions();

};

#endif // QUIZ_H