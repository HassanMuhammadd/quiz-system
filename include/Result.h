#ifndef RESULT_H
#define RESULT_H

#include "Question.h"

#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
using namespace std::chrono;

class Result {
	int id;
	float score;
	float totalScore;
	int quizId;
	int studentId;
	system_clock::time_point submissionTime;

	inline static int nextId = 1;

	public:
	Result(int quizId, int studentId, system_clock::time_point submissionTime);

	static vector<Result*> allResults;

	int getId();
	int getQuizId();
	int getStudentId();
	system_clock::time_point getSubmissionTime();
	float getScore();
	float getTotalScore();

	void displayResult();

	void setScore(float score);
	void setTotalScore(float totalScore);

	pair<float, float> calculateScore(vector<Question*>& questions, vector<string> answers);

	static Result* findResult(int studentId, int quizId);
	static vector<Result*> findQuizResults(int quizId);
	static vector<Result*> findStudentResults(int studentId);
};

#endif // RESULT_H
