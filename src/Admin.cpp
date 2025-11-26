#include "Admin.h"

#include <iostream>

Admin::Admin(string name, string email, string password)
	: User(nextId++, User::ADMIN, name, email, password) {
		allAdmins.push_back(this);
	}

vector<Admin*> Admin::allAdmins;

vector<Admin*>& Admin::getAllAdmins() { return allAdmins; }

// Template implementation
template<class T>
T& Admin::createUserOfType(string name, string email, string password, vector<T*>& storage) {
	T* obj = new T(name, email, password);
	storage.push_back(obj);
	return *obj;
}


// Template implementation
template<class T>
bool Admin::deleteUserOfType(int id, vector<T*>& storage) {
	for (auto it = storage.begin(); it != storage.end(); ++it) {
		if ((*it)->getId() == id) {
			delete *it;
			storage.erase(it);
			return true;
		}
	}
	cout << "\n===User not found===\n";
	return false;
}

// Explicit template instantiations for the types we use
template bool Admin::deleteUserOfType<Teacher>(int, vector<Teacher*>&);
template bool Admin::deleteUserOfType<Student>(int, vector<Student*>&);



