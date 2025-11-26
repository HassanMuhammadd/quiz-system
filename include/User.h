#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
public:
	enum Role {
		ADMIN,
		TEACHER,
		STUDENT
	};

protected:
	const int id;
	Role role;
	string name;
	string email;
	string password;

	public:
	User(int id, Role role, string name, string email, string password);

	int getId();
	Role getRole();
	string getName();
	string getEmail();
	string getPassword();

	void setName(string name);
	void setEmail(string email);
	void setPassword(string password);

	bool checkPassword(string password);

	protected:
	string hashPassword(string password);

};

#endif // USER_H
