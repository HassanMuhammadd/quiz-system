#include "../include/App.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Admin.h"
#include <iostream>
#include <cassert>

using namespace std;

// Test helper function to check login failure
void testLoginWithWrongEmail() {
    cout << "\n=== Test: Login with Wrong Email ===" << endl;

    // Create a test student
    Student* testStudent = new Student("Test Student", "test@example.com", "password123");
    Student::allStudents.push_back(testStudent);

    // Create App instance
    App app;

    // Try to login with wrong email
    Student* result = app.doLogin<Student>("wrong@example.com", "password123", Student::allStudents);

    // Assert that login should fail (return nullptr)
    assert(result == nullptr);
    cout << "Login with wrong email passed" << endl;

    // Cleanup
    delete testStudent;
    Student::allStudents.clear();
}

void testLoginWithWrongPassword() {
    cout << "\n=== Test: Login with Wrong Password ===" << endl;

    // Create a test student
    Student* testStudent = new Student("Test Student", "test@example.com", "password123");
    Student::allStudents.push_back(testStudent);

    // Create App instance
    App app;

    // Try to login with wrong password
    Student* result = app.doLogin<Student>("test@example.com", "wrongpassword", Student::allStudents);

    // Assert that login should fail (return nullptr)
    assert(result == nullptr);
    cout << "Login with wrong password passed" << endl;

    // Cleanup
    delete testStudent;
    Student::allStudents.clear();
}

void testLoginWithCorrectCredentials() {
    cout << "\n=== Test: Login with Correct Credentials ===" << endl;

    // Create a test teacher
    Teacher* testTeacher = new Teacher("Test Teacher", "teacher@example.com", "teacherpass");
    Teacher::allTeachers.push_back(testTeacher);

    // Create App instance
    App app;

    // Try to login with correct credentials
    Teacher* result = app.doLogin<Teacher>("teacher@example.com", "teacherpass", Teacher::allTeachers);

    // Assert that login should succeed
    assert(result != nullptr);
    assert(result->getEmail() == "teacher@example.com");
    cout << "Login with correct credentials passed" << endl;

    // Cleanup
    delete testTeacher;
    Teacher::allTeachers.clear();
}

void testLoginWithEmptyCredentials() {
    cout << "\n=== Test: Login with Empty Credentials ===" << endl;

    // Create a test student
    Student* testStudent = new Student("Test Student", "test@example.com", "password123");
    Student::allStudents.push_back(testStudent);

    // Create App instance
    App app;

    // Try to login with empty email
    Student* result1 = app.doLogin<Student>("", "password123", Student::allStudents);
    assert(result1 == nullptr);

    // Try to login with empty password
    Student* result2 = app.doLogin<Student>("test@example.com", "", Student::allStudents);
    assert(result2 == nullptr);

    cout << "Login with empty credentials passed" << endl;

    // Cleanup
    delete testStudent;
    Student::allStudents.clear();
}

void runAllAuthTests() {
    cout << "\n========================================" << endl;
    cout << "Running Authentication Tests" << endl;
    cout << "========================================" << endl;

    testLoginWithWrongEmail();
    testLoginWithWrongPassword();
    testLoginWithCorrectCredentials();
    testLoginWithEmptyCredentials();

    cout << "\n========================================" << endl;
    cout << "All Authentication Tests Passed!" << endl;
    cout << "========================================\n" << endl;
}
