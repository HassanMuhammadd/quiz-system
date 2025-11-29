<!-- NEON TITLE -->
<h1 align="center">
  <span style="
    font-size: 42px;
    font-weight: 700;
    background: linear-gradient(90deg, #00AEEF, #007BFF, #00E1FF);
    -webkit-background-clip: text;
    color: transparent;
    text-shadow: 0 0 8px rgba(0, 174, 239, 0.6);
  ">
    Quiz Management System
  </span>
</h1>

<!-- TYPING EFFECT -->
<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Segoe+UI&size=28&duration=3000&pause=500&color=00AEEF&center=true&vCenter=true&width=700&lines=Modern+C%2B%2B+Project;OOP+%7C+UML+%7C+SWE+Design;Role-Based+Exam+Platform" />
</p>

<!-- BADGES -->
<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B">
  <img src="https://img.shields.io/badge/Concepts-OOP-f06292?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-4caf50?style=for-the-badge">
  <img src="https://img.shields.io/badge/Platform-Console-9e9e9e?style=for-the-badge">
</p>

---

<!-- ANIMATED LINE -->
<p align="center">
  <img src="https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/colored.png" width="80%" />
</p>

## <span style="color:#00AEEF;">Overview</span>

<div style="border-left: 4px solid #00AEEF; padding: 12px 16px; background: #f7fbff;">
A fully featured quiz management system built with <b>Modern C++</b>  
and structured according to a complete <b>UML-based Software Engineering design approach</b>.  
It supports role-based operations for Admins, Teachers, and Students.
</div>

<br>

<b style="color:#00AEEF;">Academic Context:</b>  
This project was developed as part of the <b>Software Engineering (SWE) course</b>  
within the <b>9-Month Professional Program at the Information Technology Institute (ITI)</b>.

<br>
<b style="color:#00AEEF;">Repository Contents:</b>  
This repository contains the full project source code,  
the complete SWE Backlog, and all UML Diagrams  
(Use Case, Activity, Sequence, Class Diagrams) used for project design.


---

## <span style="color:#00AEEF;">Team Members</span>

<table>
<tr><th>Name</th></tr>
<tr><td><b>Farida Ahmed Abdelaal</b></td></tr>
<tr><td><b>Hassan Abdelhamed Hassan</b></td></tr>
<tr><td><b>Hassan Muhammad Hassan</b></td></tr>
<tr><td><b>Marwa Ashraf Abdullah</b></td></tr>
<tr><td><b>Mazen Raafat Abdelhameed Mostafa</b></td></tr>
</table>

---

## <span style="color:#00AEEF;">Key Features</span>

### <span style="color:#007BFF;">Students</span>
- Real-time quiz interface  
- Automatic grading  
- Auto-save + forced submission on timeout  

### <span style="color:#007BFF;">Teachers</span>
- Create quizzes with time limits  
- Add / edit / remove MCQs  
- View results by quiz or student  

### <span style="color:#007BFF;">Admins</span>
- Create and manage accounts  
- Assign system roles  
- Secure login validation  

---

## <span style="color:#00AEEF;">Technical Highlights</span>

<table>
<tr><th>Concept</th><th>Details</th></tr>
<tr><td>Inheritance</td><td>`User` extended by `Admin`, `Teacher`, `Student`</td></tr>
<tr><td>Abstraction</td><td>Abstract base class for user behavior</td></tr>
<tr><td>Encapsulation</td><td>Private fields (password, score)</td></tr>
<tr><td>Polymorphism</td><td>Role-specific overridden methods</td></tr>
</table>

---

## <span style="color:#00AEEF;">System Architecture</span>

The project includes all required UML documentation:
- Use Case Diagram  
- Class Diagram  
- Sequence Diagrams  
- Activity Diagrams  
- Full Backlog (User Stories, Tasks)

All files are included in the repository.

---

## <span style="color:#00AEEF;">How to Run</span>

```bash
git clone https://github.com/HassanMuhammadd/quiz-system.git
g++ -g src/*.cpp -o src/build/Debug/outDebug.exe -Iinclude
src/build/Debug/outDebug.exe
```

## <span style="color:#00AEEF;">How to Run tests</span>

```bash
git clone https://github.com/HassanMuhammadd/quiz-system.git
g++ -std=c++17 -o test/build/test_runner test/test_main.cpp src/App.cpp src/User.cpp src/Student.cpp src/Teacher.cpp src/Admin.cpp src/Quiz.cpp src/Question.cpp src/Option.cpp src/Result.cpp -I./include
./test/build/test_runner
```


