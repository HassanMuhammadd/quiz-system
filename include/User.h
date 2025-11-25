#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
	const int id;
	string name;
	string email;
	string password;
	inline static int nextId = 1;

	public:
	User(string name, string email, string password);

	int getId();
	string getName();
	string getEmail();
	string getPassword();

	void setName(string name);
	void setEmail(string email);
	void setPassword(string password);

	User& login(string email, string password);

	protected:
	string hashPassword(string password);

};

#endif // USER_H