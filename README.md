# Quiz System

### Features

- User Authentication
- Quiz Management
- Quiz Creation
- Quiz Taking
- Viewing Results

To build:\
`g++ -g src/*.cpp -o src/build/Debug/outDebug.exe -Iinclude`

To run:\
`src/build/Debug/outDebug.exe`

To test:\
`g++ -std=c++17 -o test/build/test_runner test/test_main.cpp src/App.cpp src/User.cpp src/Student.cpp src/Teacher.cpp src/Admin.cpp src/Quiz.cpp src/Question.cpp src/Option.cpp src/Result.cpp -I./include`

To run tests:\
`./test/build/test_runner`
