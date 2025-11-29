#include "test_auth.cpp"
#include "test_quiz.cpp"
#include "test_utilities.cpp"
#include "test_question.cpp"
#include <iostream>

using namespace std;

int main() {
    cout << "===========Quiz System Test Suite===========\n" << endl;

    try {
        runAllAuthTests();

        runAllQuizTests();

        runAllUtilityTests();

        runAllQuestionTests();

        cout << "\n===========ALL TESTS PASSED===========\n" << endl;

        return 0;
    } catch (const exception& e) {
        cerr << "\nTest failed with exception: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "\nTest failed with unknown exception" << endl;
        return 1;
    }
}
