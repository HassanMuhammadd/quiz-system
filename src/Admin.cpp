#include "Admin.h"

template<class T>
T& Admin::createUserOfType(string name, string email, string password, vector<T*>& storage) {
	T* obj = new T(name, email, password);
	storage.push_back(obj);
	return *obj;
}