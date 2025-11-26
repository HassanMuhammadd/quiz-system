#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Student.h"
#include "Teacher.h"

#include <vector>

class Admin : public User {
	inline static int nextId = 1;


	public:
	static vector<Admin*> allAdmins;
	Admin(string name, string email, string password);

	template<class T>
	T& createUserOfType(string name, string email, string password, vector<T*>& storage);

	template<class T>
	bool deleteUserOfType(int id, vector<T*>& storage);

	static vector<Admin*>& getAllAdmins();
};

#endif // ADMIN_H
