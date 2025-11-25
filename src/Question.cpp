#include "Question.h"

Question::Question(string text, float points) : id(++nextId), text(text), points(points) {}

Question& Question::addOption(string text, bool isCorrect) {
	Option *option = new Option(text, isCorrect);
	options.push_back(option);

	return *this;
}

bool Question::checkAnswer(string studentAnswer) {
	for (const Option *option : options) {
		if (option->getText() == studentAnswer) {
			return option->isCorrect();
		}
	}
	return false;
}