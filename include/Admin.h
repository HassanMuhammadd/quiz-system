#include "User.h"
#include "Student.h"
#include "Teacher.h"

#include <vector>

class Admin : public User {
private:

	template<class T>
	T& createUserOfType(string name, string email, string password, vector<T*>& storage) {
		T* obj = new T(name, email, password);
		storage.push_back(obj);
		return *obj;
	}

public:
	Admin(string name, string email, string password);

	User& createUser(string name, string email, string password);

	// Specialized methods that use the template with static storage
	Student& createStudent(string name, string email, string password) {
		return createUserOfType<Student>(name, email, password, Student::getAllStudents());
	}

	Teacher& createTeacher(string name, string email, string password) {
		return createUserOfType<Teacher>(name, email, password, Teacher::getAllTeachers());
	}
};