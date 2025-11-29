#include "../include/User.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Quiz.h"
#include "../include/Question.h"
#include <iostream>
#include <cassert>

using namespace std;

void testUserPasswordHashing() {
    cout << "\n=== Test: Password Hashing ===" << endl;

    // Create a student
    Student* student = new Student("Test User", "test@example.com", "mypassword");

    // Verify that the stored password is hashed (not plain text)
    assert(student->getPassword() != "mypassword");

    // Verify that checkPassword works correctly
    assert(student->checkPassword("mypassword") == true);
    assert(student->checkPassword("wrongpassword") == false);

    cout << "Password hashing works correctly" << endl;

    // Cleanup
    delete student;
}

void testUserGetters() {
    cout << "\n=== Test: User Getters ===" << endl;

    // Create a teacher
    Teacher* teacher = new Teacher("John Doe", "john@example.com", "pass123");

    // Verify getters return correct values
    assert(teacher->getName() == "John Doe");
    assert(teacher->getEmail() == "john@example.com");
    assert(teacher->getRole() == User::TEACHER);

    cout << "User getters work correctly" << endl;

    // Cleanup
    delete teacher;
}

void testQuizCreation() {
    cout << "\n=== Test: Quiz Creation ===" << endl;

    // Create a teacher and quiz
    Teacher* teacher = new Teacher("Test Teacher", "teacher@test.com", "pass");
    Quiz* quiz = teacher->createQuiz(45, "Math Quiz", 2025, 12, 25, 10, 30);

    // Verify quiz was created
    assert(quiz != nullptr);
    assert(quiz->getTimeLimitInMinutes() == 45);
    assert(teacher->getQuizzes().size() == 1);

    cout << "Quiz creation works correctly" << endl;

    // Cleanup
    teacher->deleteQuiz(quiz->getId());
    delete teacher;
}

void testQuestionAddition() {
    cout << "\n=== Test: Question Addition to Quiz ===" << endl;

    // Create a teacher and quiz
    Teacher* teacher = new Teacher("Test Teacher", "teacher@test.com", "pass");
    Quiz* quiz = teacher->createQuiz(30, "Science Quiz", 2025, 11, 30, 9, 0);

    // Add questions to quiz
    Question* q1 = quiz->addQuestion("What is H2O?", 5.0f);
    Question* q2 = quiz->addQuestion("What is CO2?", 5.0f);

    // Verify questions were added
    assert(q1 != nullptr);
    assert(q2 != nullptr);
    assert(quiz->getQuestions().size() == 2);

    cout << "Question addition works correctly" << endl;

    // Cleanup
    teacher->deleteQuiz(quiz->getId());
    delete teacher;
}

void testMultipleQuizzes() {
    cout << "\n=== Test: Multiple Quizzes per Teacher ===" << endl;

    // Create a teacher
    Teacher* teacher = new Teacher("Test Teacher", "teacher@test.com", "pass");

    // Create multiple quizzes
    Quiz* quiz1 = teacher->createQuiz(30, "Quiz 1", 2025, 11, 1, 10, 0);
    Quiz* quiz2 = teacher->createQuiz(45, "Quiz 2", 2025, 11, 15, 14, 0);
    Quiz* quiz3 = teacher->createQuiz(60, "Quiz 3", 2025, 12, 1, 9, 30);

    // Verify all quizzes were created
    assert(teacher->getQuizzes().size() == 3);

    // Delete one quiz
    teacher->deleteQuiz(quiz2->getId());
    assert(teacher->getQuizzes().size() == 2);

    cout << "Multiple quizzes management works correctly" << endl;

}

void runAllUtilityTests() {
    cout << "\n========================================" << endl;
    cout << "Running Utility Tests" << endl;
    cout << "========================================" << endl;

    testUserPasswordHashing();
    testUserGetters();
    testQuizCreation();
    testQuestionAddition();
    testMultipleQuizzes();

    cout << "\n========================================" << endl;
    cout << "All Utility Tests Passed!" << endl;
    cout << "========================================\n" << endl;
}
