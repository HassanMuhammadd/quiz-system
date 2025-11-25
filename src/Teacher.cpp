#include "Teacher.h"

vector<Teacher*> Teacher::allTeachers;

Teacher::Teacher(string name, string email, string password)
	: User(name, email, password) {}

vector<Teacher*>& Teacher::getAllTeachers() { return allTeachers; }
