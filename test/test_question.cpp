#include "../include/Question.h"
#include <iostream>
#include <cassert>

using namespace std;

int countCorrectAnswers(Question* question) {
    int correctCount = 0;
    vector<string> options = question->getOptions();

    for (const string& option : options) {
        if (question->checkAnswer(option)) {
            correctCount++;
        }
    }

    return correctCount;
}

void testQuestionWithOneCorrectAnswer() {
    cout << "\n=== Test: Question with One Correct Answer ===" << endl;

    Question* question = new Question("What is the capital of France?", 5.0);
    question->addOption("Berlin", false)
            .addOption("Madrid", false)
            .addOption("Paris", true)
            .addOption("Rome", false);

    int correctCount = countCorrectAnswers(question);
    assert(correctCount == 1);

    assert(question->getText() == "What is the capital of France?");
    assert(question->getPoints() == 5.0);
    assert(question->getOptions().size() == 4);

    cout << "Question with one correct answer passed" << endl;

    delete question;
}

void testQuestionWithNoCorrectAnswer() {
    cout << "\n=== Test: Question with No Correct Answer ===" << endl;

    Question* question = new Question("Which color is best?", 3.0);
    question->addOption("Red", false)
            .addOption("Blue", false)
            .addOption("Green", false)
            .addOption("Yellow", false);

    int correctCount = countCorrectAnswers(question);
    assert(correctCount == 1);


    assert(question->getText() == "Which color is best?");
    assert(question->getPoints() == 3.0);
    assert(question->getOptions().size() == 4);

    cout << "Question with no correct answer passed (INVALID QUESTION DETECTED)" << endl;

    delete question;
}

void testQuestionWithMultipleCorrectAnswers() {
    cout << "\n=== Test: Question with Multiple Correct Answers ===" << endl;

    Question* question = new Question("Which are programming languages?", 10.0);
    question->addOption("Python", true)
            .addOption("HTML", false)
            .addOption("Java", true)
            .addOption("CSS", false)
            .addOption("C++", true);

    int correctCount = countCorrectAnswers(question);
    assert(correctCount == 1);

    assert(question->getText() == "Which are programming languages?");
    assert(question->getPoints() == 10.0);
    assert(question->getOptions().size() == 5);

    cout << "Question with multiple correct answers passed (INVALID QUESTION DETECTED)" << endl;

    delete question;
}

void runAllQuestionTests() {
    cout << "\n========================================" << endl;
    cout << "Running Question Validation Tests" << endl;
    cout << "========================================" << endl;

    testQuestionWithOneCorrectAnswer();
    testQuestionWithNoCorrectAnswer();
    testQuestionWithMultipleCorrectAnswers();

    cout << "\n========================================" << endl;
    cout << "All Question Validation Tests Passed!" << endl;
    cout << "========================================\n" << endl;
}
