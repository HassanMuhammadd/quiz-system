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

float Question::getPoints() { return points; }

string Question::getText() { return text; }

int Question::getId() { return id; }

// Here, we're only returning the text and keeping the score hidden for security
vector<string> Question::getOptions() {
	vector<string> optionsText;
	for (const Option *option : options) {
		optionsText.push_back(option->getText());
	}
	return optionsText;
}

bool Question::hasCorrectOption() {
		for (const Option *option : options) {
				if (option->isCorrect()) {
						return true;
				}
		}
		return false;
}