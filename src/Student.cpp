#include "Student.h"

vector<Student*> Student::allStudents;

Student::Student(string name, string email, string password)
	: User(name, email, password) {}

vector<Student*>& Student::getAllStudents() { return allStudents; }