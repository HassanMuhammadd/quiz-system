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

User::User(int id, Role role, string name, string email, string password)
	: id(id), role(role), name(name), email(email), password(hashPassword(password)) {}

string User::getName() { return name; }
string User::getEmail() { return email; }
string User::getPassword() { return password; }

void User::setName(string name) { this->name = name; }
void User::setEmail(string email) { this->email = email; }
void User::setPassword(string password) {
	this->password = hashPassword(password);
}

bool User::checkPassword(string password) {
	return this->password == hashPassword(password);
}



int User::getId() { return id; }
User::Role User::getRole() { return role; }

