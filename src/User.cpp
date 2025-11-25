#include "User.h"

#include <sstream>
#include <iomanip>
#include <functional>
#include <iostream>

string User::hashPassword(string password) {
	hash<string> hasher;
	size_t hashValue = hasher(password);

	stringstream ss;

	// Set the hashed password to be 16 char & Hex
	ss << hex << setw(16) << hashValue;

	return ss.str();
}

User::User(string name, string email, string password)
	: id(nextId++), name(name), email(email), password(hashPassword(password)) {}

int User::getId() { return id; }
string User::getName() { return name; }
string User::getEmail() { return email; }
string User::getPassword() { return password; }

void User::setName(string name) { this->name = name; }
void User::setEmail(string email) { this->email = email; }
void User::setPassword(string password) {
	this->password = hashPassword(password);
}

User& User::login(string email, string password) {
	if(this->email == email && this->password == hashPassword(password))
		return *this;
	else {
		cout << "Invalid email or password" << endl;
		return *this;
	}
}


