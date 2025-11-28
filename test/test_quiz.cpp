#include "../include/Teacher.h"
#include "../include/Quiz.h"
#include <iostream>
#include <cassert>

using namespace std;

void testDeleteNonExistentQuiz() {
    cout << "\n=== Test: Delete Non-Existent Quiz ===" << endl;

    // Create a test teacher
    Teacher* teacher = new Teacher("Test Teacher", "teacher@test.com", "pass123");

    // Try to delete a quiz that doesn't exist (ID 999)
    bool result = teacher->deleteQuiz(999);

    // Assert that deletion should fail (return false)
    assert(result == false);
    cout << "Deleting non-existent quiz passed" << endl;

    // Cleanup
    delete teacher;
}

void testDeleteExistingQuiz() {
    cout << "\n=== Test: Delete Existing Quiz ===" << endl;

    // Create a test teacher
    Teacher* teacher = new Teacher("Test Teacher", "teacher@test.com", "pass123");

    // Create a quiz
    Quiz* quiz = teacher->createQuiz(60, "Test Quiz", 2025, 12, 31, 10, 0);
    int quizId = quiz->getId();

    // Verify quiz exists in teacher's quizzes
    assert(teacher->getQuizzes().size() == 1);

    // Delete the quiz
    bool result = teacher->deleteQuiz(quizId);

    // Assert that deletion succeeded
    assert(result == true);
    assert(teacher->getQuizzes().size() == 0);
    cout << "Deleting existing quiz passed" << endl;

    // Cleanup
    delete teacher;
}


void testDeleteWrongQuizId() {
    cout << "\n=== Test: Delete Wrong Quiz ID ===" << endl;

    // Create a test teacher
    Teacher* teacher = new Teacher("Test Teacher", "teacher@test.com", "pass123");

    // Create multiple quizzes
    Quiz* quiz1 = teacher->createQuiz(30, "Quiz 1", 2025, 11, 1, 9, 0);
    Quiz* quiz2 = teacher->createQuiz(45, "Quiz 2", 2025, 11, 15, 14, 30);
    int quiz1Id = quiz1->getId();

    // Verify we have 2 quizzes
    assert(teacher->getQuizzes().size() == 2);

    // Try to delete with wrong ID (not in list)
    bool result = teacher->deleteQuiz(1000);

    // Assert that deletion failed and both quizzes still exist
    assert(result == false);
    assert(teacher->getQuizzes().size() == 2);
    cout << "Deleting with wrong quiz ID passed" << endl;

}

void runAllQuizTests() {
    cout << "\n========================================" << endl;
    cout << "Running Quiz Deletion Tests" << endl;
    cout << "========================================" << endl;

    testDeleteNonExistentQuiz();
    testDeleteExistingQuiz();
    testDeleteWrongQuizId();

    cout << "\n========================================" << endl;
    cout << "All Quiz Deletion Tests Passed!" << endl;
    cout << "========================================\n" << endl;
}
