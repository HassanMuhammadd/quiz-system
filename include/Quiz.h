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

	Quiz(int timeLimitInMinutes, string title);

	system_clock::time_point getPublishAt();
	int getId();

	void setTimeLimitInMinutes(int timeLimitInMinutes);
	void setTitle(string title);

	static vector<Quiz*>& getAllQuizzes();
	static Quiz* findQuiz(int id);

	void displayQuiz();

	void publishQuiz(int year, int month, int day, int hour, int minute);


	Quiz& addQuestion(string text, float points);
	Quiz& removeQuestion(int questionId);
	vector<Question*>& getQuestions();

};

#endif // QUIZ_H
