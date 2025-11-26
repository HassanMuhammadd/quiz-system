#include "Result.h"

#include <iostream>


vector<Result*> Result::allResults;

Result::Result(int quizId, int studentId, system_clock::time_point submissionTime) : id(id), quizId(quizId), studentId(studentId), submissionTime(submissionTime) {
	this->id = nextId++;
	allResults.push_back(this);
}

int Result::getId() { return id; }
int Result::getQuizId() { return quizId; }
int Result::getStudentId() { return studentId; }
float Result::getScore() { return score; }
float Result::getTotalScore() { return totalScore; }
system_clock::time_point Result::getSubmissionTime() { return submissionTime; }

void Result::setScore(float score) { this->score = score; }
void Result::setTotalScore(float totalScore) { this->totalScore = totalScore; }

pair<float, float> Result::calculateScore(vector<Question*>& questions, vector<string> answers) {
	float score = 0;
	float totalScore = 0;
	for (int i = 0; i < questions.size(); i++) {
		if (questions[i]->checkAnswer(answers[i])) {
			score += questions[i]->getPoints();
		}
		totalScore += questions[i]->getPoints();
	}
	setScore(score);
	setTotalScore(totalScore);
	return make_pair(score, totalScore);
}

void Result::displayResult() {
	cout << "Student ID: " << getStudentId() << endl;
	cout << "Quiz ID: " << getQuizId() << endl;
	cout << "Score: " << getScore() << endl;
	cout << "Total Score: " << getTotalScore() << endl;
	time_t submissionTimeT = system_clock::to_time_t(getSubmissionTime());
	cout << "Submitted At: " << ctime(&submissionTimeT);
}


Result* Result::findResult(int studentId, int quizId) {
	for (Result *result : allResults) {
		if (result->getStudentId() == studentId && result->getQuizId() == quizId) {
			return result;
		}
	}
	cout << "\n===Result not found===\n";
	return nullptr;
}

vector<Result*> Result::findQuizResults(int quizId) {
	vector<Result*> results;
	for (Result *result : allResults) {
		if (result->getQuizId() == quizId) {
			results.push_back(result);
		}
	}
	return results;
}

vector<Result*> Result::findStudentResults(int studentId) {
	vector<Result*> results;
	for (Result *result : allResults) {
		if (result->getStudentId() == studentId) {
			results.push_back(result);
		}
	}
	return results;
}