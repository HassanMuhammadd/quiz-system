#include "Quiz.h"

#include <iostream>

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
	: id(nextId++), timeLimitInMinutes(timeLimitInMinutes), title(title), publishAt(createTimePoint(year, month, day, hour, minute)) {
		allQuizzes.push_back(this);
	}


system_clock::time_point Quiz::getPublishAt() { return publishAt; }
int Quiz::getId() { return id; }
int Quiz::getTimeLimitInMinutes() { return timeLimitInMinutes; }

vector<Quiz*>& Quiz::getAllQuizzes() { return allQuizzes; }

void Quiz::setTimeLimitInMinutes(int timeLimitInMinutes) { this->timeLimitInMinutes = timeLimitInMinutes; }
void Quiz::setTitle(string title) { this->title = title; }

// add the publishAt time to the quiz
void Quiz::publishQuiz(int year, int month, int day, int hour, int minute) {
	this->publishAt = createTimePoint(year, month, day, hour, minute);
}


Question* Quiz::addQuestion(string text, float points) {
	Question *question = new Question(text, points);
	questions.push_back(question);
	return question;
}

Quiz& Quiz::removeQuestion(int questionId) {
	for (auto it = questions.begin(); it != questions.end(); ++it) {
		if((*it)->getId() == questionId) {
			questions.erase(it);
			delete *it;
			return *this;
		}
	}
	cout << "\n===Question not found===\n";
	return *this;
}

vector<Question*>& Quiz::getQuestions() { return questions; }

Quiz* Quiz::findQuiz(int id) {
	for (Quiz *quiz : allQuizzes) {
		if (quiz->getId() == id) {
			return quiz;
		}
	}
	cout << "\n===Quiz not found===\n";
	return nullptr;
}

void Quiz::displayQuiz() {
	time_t publishAt_timeT = system_clock::to_time_t(publishAt);
	cout << "\n=======\n";
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "Time Limit: " << timeLimitInMinutes << " minutes" << endl;
	cout << "Available At: " << ctime(&publishAt_timeT) << endl;
}

