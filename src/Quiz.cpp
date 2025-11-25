#include "Quiz.h"

vector<Quiz*> Quiz::allQuizzes;

// Helper function to convert date/time components to time_point
system_clock::time_point createTimePoint(int year, int month, int day, int hour, int minute) {
	tm timeStruct = {};
	timeStruct.tm_year = year - 1900;  // Years since 1900
	timeStruct.tm_mon = month - 1;      // Months since January (0-11)
	timeStruct.tm_mday = day;
	timeStruct.tm_hour = hour;
	timeStruct.tm_min = minute;
	timeStruct.tm_sec = 0;

	time_t timeT = mktime(&timeStruct);
	return system_clock::from_time_t(timeT);
}

Quiz::Quiz(int timeLimitInMinutes, string title, int year, int month, int day, int hour, int minute)
	: id(nextId++), timeLimitInMinutes(timeLimitInMinutes), title(title), activeAt(createTimePoint(year, month, day, hour, minute)) {}


system_clock::time_point Quiz::getActiveAt() { return activeAt; }
int Quiz::getId() { return id; }

vector<Quiz*>& Quiz::getAllQuizzes() { return allQuizzes; }

void publishQuiz(Quiz quiz) {
	Quiz::allQuizzes.push_back(&quiz);
}

void unpublishQuiz(int id) {
	for (int i = 0; i < Quiz::allQuizzes.size(); i++) {
		if (Quiz::allQuizzes[i]->getId() == id) {
			Quiz::allQuizzes.erase(Quiz::allQuizzes.begin() + i);
			delete Quiz::allQuizzes[i];
			Quiz::allQuizzes[i] = nullptr;
			break;
		}
	}
}

Quiz& Quiz::addQuestion(string text, float points) {
	Question *question = new Question(text, points);
	questions.push_back(question);
	return *this;
}
