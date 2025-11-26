#include <iostream>
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

int main(){

	Admin admin("admin", "admin", "admin");
	admin.createUserOfType<Teacher>("teacher", "teacher", "teacher", Teacher::allTeachers);
	admin.createUserOfType<Student>("student", "student", "student", Student::allStudents);

	cout << "Teachers: " << Teacher::allTeachers.size() << endl;
	cout << "Students: " << Student::allStudents.size() << endl;
	for (const auto& teacher : Teacher::allTeachers) {
		cout << teacher->getName() << endl;
	}
	for (const auto& student : Student::allStudents) {
		cout << student->getName() << endl;
	}

	admin.deleteUserOfType<Teacher>(1, Teacher::allTeachers);
	admin.deleteUserOfType<Student>(2, Student::allStudents);

	cout << "Teachers: " << Teacher::allTeachers.size() << endl;
	cout << "Students: " << Student::allStudents.size() << endl;
	for (const auto& teacher : Teacher::allTeachers) {
		cout << teacher->getName() << ", Role: " << teacher->getRole() << endl;
	}
	for (const auto& student : Student::allStudents) {
		cout << student->getName() << ", Role: " << student->getRole() << endl;
	}

	return 0;
}