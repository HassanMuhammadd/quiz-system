### \#1 Login

**Category:** User Accounts

**Stage:** Planned

**Importance:** Urgent



#### Description

**User Story:**

As a User, I want to login so I can access my role-specific console.



**Acceptance Criteria:**

* Correct credentials allow login
* Wrong input shows an error
* Loads < 1 second



**Tasks:**

* Login UI
* Validate inputs
* Role redirection

============================================================================================================================================================================================

### \#2 Logout

**Category:** User Accounts

**Stage:** Planned

**Importance:** High



#### Description

**User Story:**

As a User, I want to logout so I can exit securely.



**Acceptance Criteria:**

* Session cleared
* Redirect to login



**Tasks:**

* Implement logout
* Validate inputs
* Clear session

============================================================================================================================================================================================

### \#3 Create Account (Admin)

**Category:** User Accounts

**Stage:** Planned

**Importance:** Urgent



#### Description

**User Story:**

As an Admin, I want to create accounts for teachers and students so they can access the system.



**Acceptance Criteria:**

* Admin can add user email, username, and role
* System validates inputs



**Tasks:**

* Console Form
* Validation logic
* Save users in memory

============================================================================================================================================================================================

### \#4 Create Quiz

**Category:** Quiz Creation

**Stage:** Planned

**Importance:** Urgent



#### Description

**User Story:**

As a Teacher, I want to create quizzes with time limits and a start date.



**Acceptance Criteria:**

* Quiz must have a name + description + start date
* Time limit is required
* System validates inputs



**Tasks:**

* Quiz creation UI
* Add date
* Add timer
* Save quiz in memory

============================================================================================================================================================================================

### \#5 Edit Quiz

**Category:** Quiz Creation

**Stage:** Planned

**Importance:** Normal



#### Description

**User Story:**

As a teacher, I would like to edit quiz information.

============================================================================================================================================================================================

### \#6 Delete Quiz

**Category:** Quiz Creation

**Stage:** Planned

**Importance:** Normal



#### Description

**User Story:**

As a teacher, I would like to delete the quiz.

============================================================================================================================================================================================

### \#7 Add Questions

**Category:** Question Manage

**Stage:** Planned

**Importance:** Urgent



#### Description

**User Story:**

As a Teacher, I want to add questions to make the quiz functional.



**Acceptance Criteria:**

* Question text required
* At least 2 options
* 1 correct answer



**Tasks:**

* Question UI
* Options handling
* Save question in memory

============================================================================================================================================================================================

### \#8 Edit Questions

**Category:** Question Manage

**Stage:** Planned

**Importance:** Normal



#### Description

**User Story:**

As a Teacher, I want to edit questions to update the quiz info.

============================================================================================================================================================================================

### \#9 Delete Questions

**Category:** Question Manage

**Stage:** Planned

**Importance:** Normal



#### Description

**User Story:**

As a Teacher, I want to delete questions from the quiz.

============================================================================================================================================================================================

### \#10 Take Quiz

**Category:** Quiz Taking

**Stage:** Planned

**Importance:** Urgent



#### Description

**User Story:**

As a Student, I want to take quizzes and submit answers.



**Acceptance Criteria:**

* The quiz only opens when the date and time are reached
* Shows questions in order
* Timer visible
* Auto-submit when time ends



**Tasks:**

* Publish Quiz Handling
* Quiz UI
* Timer binding
* Submit answers

============================================================================================================================================================================================

### \#11 Timer Handling

**Category:** Quiz Taking

**Stage:** Planned

**Importance:** Urgent



#### Description

**User Story:**

As the System, I must enforce the time limit.



**Acceptance Criteria:**

* Auto-submit on timeout
* Timer can't be paused



**Tasks:**

* Time countdown
* Link timer to quiz

============================================================================================================================================================================================

### \#12 Auto Grade Quiz

**Category:** Quiz Taking

**Stage:** Planned

**Importance:** High



#### Description

**User Story:**

As the System, I want to auto-grade the quiz.



**Acceptance Criteria:**

* Compare student answers
* Generate score
* Save result



**Tasks:**

* Grading logic
* Answer comparison
* Result storage

============================================================================================================================================================================================

### \#13 View Students Results (Teacher)

**Category:** Result Management

**Stage:** Planned

**Importance:** Normal



#### Description

**User Story:**

As a Teacher, I want to view student scores.



**Acceptance Criteria:**

* List scores
* Filter by quiz/student



**Tasks:**

* Results UI
* Sorting logic

============================================================================================================================================================================================

### \#14 View My Results (Student)

**Category:** Result Management

**Stage:** Planned

**Importance:** Normal



#### Description

**User Story:**

As a Student, I want to see my own quiz scores.



**Tasks:**

* Results UI

============================================================================================================================================================================================

### \#15 System Loads Under 1 Second

**Category:** Non-Functional System Requirements

**Stage:** Planned

**Importance:** High

============================================================================================================================================================================================

### \#16 Handle at least 50 Users Concurrently

**Category:** Non-Functional System Requirements

**Stage:** Planned

**Importance:** Low

============================================================================================================================================================================================

### \#17 Input Validation Everywhere

**Category:** Non-Functional System Requirements

**Stage:** Planned

**Importance:** Urgent

============================================================================================================================================================================================

### \#18 System Does Not Crash (Graceful Exit)

**Category:** Non-Functional System Requirements

**Stage:** Planned

**Importance:** Urgent

============================================================================================================================================================================================

### \#19 The system should be available 99.5% of the time

**Category:** Non-Functional System Requirements

**Stage:** Planned

**Importance:** High

============================================================================================================================================================================================

### \#20 Any failure should show a friendly error message

**Category:** Non-Functional System Requirements

**Stage:** Planned

**Importance:** Normal

============================================================================================================================================================================================

### \#21 Role-based access control

**Category:** Non-Functional System Requirements (Secuirty)

**Stage:** Planned

**Importance:** Urgent

============================================================================================================================================================================================

### \#22 Console UI must be simple and intuitive for all users

**Category:** Non-Functional System Requirements (UI/UX)

**Stage:** Planned

**Importance:** Normal

============================================================================================================================================================================================

### \#23 Passwords must be stored using hashing

**Category:** Non-Functional System Requirements (Secuirty)

**Stage:** Planned

**Importance:** Urgent

============================================================================================================================================================================================

### 



