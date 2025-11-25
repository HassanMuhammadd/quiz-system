#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Student.h"
#include "Teacher.h"

#include <vector>

class Admin : public User {
private:

	template<class T>
	T& createUserOfType(string name, string email, string password, vector<T*>& storage);

public:
	Admin(string name, string email, string password);

	User& createUser(string name, string email, string password);


};

#endif // ADMIN_H