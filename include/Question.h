#include "Option.h"

#include <vector>

class Question {

	int id;
	string text;
	float points;
	vector<Option*> options;
	inline static int nextId = 0;

	public:
	Question(string text, float points);

	Question& addOption(string text, bool isCorrect);
	bool checkAnswer(string studentAnswer);

};