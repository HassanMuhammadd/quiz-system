#include "Admin.h"
#include "App.h"

#include <iostream>

Admin::Admin(string name, string email, string password)
	: User(nextId++, User::ADMIN, name, email, password) {
		allAdmins.push_back(this);
	}

vector<Admin*> Admin::allAdmins;

vector<Admin*>& Admin::getAllAdmins() { return allAdmins; }

template<class T>
T* Admin::createUserOfType(string name, string email, string password, vector<T*>& storage) {

	T* obj = new T(name, email, password);
	storage.push_back(obj);
	return obj;
}

template<class T>
bool Admin::deleteUserOfType(int id, vector<T*>& storage) {
	for (auto it = storage.begin(); it != storage.end(); ++it) {
		if ((*it)->getId() == id) {
			delete *it;
			storage.erase(it);
			cout << "\n===User deleted===\n";
			return true;
		}
	}
	cout << "\n===User not found===\n";
	return false;
}

// Explicit template instantiations for the types we use
template bool Admin::deleteUserOfType<Teacher>(int, vector<Teacher*>&);
template bool Admin::deleteUserOfType<Student>(int, vector<Student*>&);

void Admin::displayMenu() {
	int choice;
	bool finished = false;
	while (true) {
		cout << "\n===Welcome " << this->getName() << "===\n";
		cout << "1. Create Teacher\n";
		cout << "2. Create Student\n";
		cout << "3. Delete Teacher\n";
		cout << "4. Delete Student\n";
		cout << "5. Logout\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if(cin.fail()) {
			App::clearWrongInput();
			continue;
		}

		switch (choice) {
			case 1: {
				prepareCreateUserOfType<Teacher>(Teacher::allTeachers);
				break;
			}
			case 2: {
				prepareCreateUserOfType<Student>(Student::allStudents);
				break;
			}
			case 3: {
				prepareDeleteUserOfType<Teacher>(Teacher::allTeachers);
				break;
			}
			case 4: {
				prepareDeleteUserOfType<Student>(Student::allStudents);
				break;
			}
			case 5: {
				finished = true;
				break;
			}
			default: {
				cout << "\n===Invalid choice===\n";
				break;
			}
		}
		if (finished) break;
	}
}


template<class T>
T* Admin::prepareCreateUserOfType(vector<T*>& storage) {
	string name;
	string email;
	string password;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter email: ";
	cin >> email;
	cout << "Enter password: ";
	cin >> password;
	return createUserOfType<T>(name, email, password, storage);
}

template<class T>
bool Admin::prepareDeleteUserOfType(vector<T*>& storage) {
	int id;
	cout << "Enter ID: ";
	cin >> id;

	if(cin.fail()) {
		App::clearWrongInput();
		return false;
	}

	return deleteUserOfType<T>(id, storage);
}

Admin::~Admin() {
	for (auto it = Admin::getAllAdmins().begin(); it != Admin::getAllAdmins().end(); ++it) {
		if (*it == this) {
			Admin::getAllAdmins().erase(it);
			break;
		}
	}
}