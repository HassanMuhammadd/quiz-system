# Quiz System Tests

This directory contains basic assertion-based tests for the quiz system application.

### Compilation

To compile the test suite, run:

```bash
g++ -std=c++17 -o test_runner test/test_main.cpp src/App.cpp src/User.cpp src/Student.cpp src/Teacher.cpp src/Admin.cpp src/Quiz.cpp src/Question.cpp src/Option.cpp src/Result.cpp -I./include
```

### Execution

After compilation, run the tests:

```bash
./test_runner
```

## Test Framework

These tests use native C++ `assert` statements from `<cassert>` library:

- Tests will pass silently when assertions succeed
- Tests will terminate immediately if an assertion fails
- Custom success messages are printed for passed tests

## Expected Output

When all tests pass, you should see:

```
╔════════════════════════════════════════╗
║     Quiz System Test Suite             ║
╚════════════════════════════════════════╝

========================================
Running Authentication Tests
========================================

=== Test: Login with Wrong Email ===
✓ Login with wrong email correctly failed

=== Test: Login with Wrong Password ===
✓ Login with wrong password correctly failed

... (more tests)

╔════════════════════════════════════════╗
║  ALL TESTS PASSED SUCCESSFULLY! ✓✓✓   ║
╚════════════════════════════════════════╝
```

## Adding New Tests

To add new tests:

1. Create a new test file in the `test/` directory (e.g., `test_results.cpp`)
2. Include necessary headers from `../include/`
3. Write test functions using `assert()` statements
4. Create a `runAll*Tests()` function to group your tests
5. Add the test file include and function call to `test_main.cpp`

## Notes

⚠️ **Important**: These are basic unit tests using assertions. For more comprehensive testing, consider integrating a proper testing framework like Google Test or Catch2.
