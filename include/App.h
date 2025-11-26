#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

#include "Admin.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class App {
public:
    template<class T>
    T* doLogin(string email, string password, vector<T*>& users);

    template<class T>
    T* takeLoginInput(vector<T*>& users);

    void run();
};

#endif // APP_H
