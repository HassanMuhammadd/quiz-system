#include "App.h"

#include <iostream>


using namespace std;


template<class T>
T* App::doLogin(string email, string password, vector<T*>& users) {
    for (T* user : users) {
        if (user->getEmail() == email && user->checkPassword(password)) {
            return user;
        }
    }
    return nullptr;
}

void App::clearWrongInput(){
    cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n===Invalid choice===\n";
}

void App::run() {
    int choice;
    while (true) {
        cout << "1. Admin login" << endl;
        cout << "2. Teacher login" << endl;
        cout << "3. Student login" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(cin.fail()) {
			App::clearWrongInput();
			continue;
		}

        switch (choice) {
            case 1: {
                Admin* a = takeLoginInput<Admin>(Admin::allAdmins);
                a->displayMenu();
                break;
            }
            case 2: {
                Teacher* t = takeLoginInput<Teacher>(Teacher::allTeachers);
                t->displayMenu();
                break;
            }
            case 3: {
                Student* s = takeLoginInput<Student>(Student::allStudents);
                s->displayMenu();
                break;
            }
            case 4: {
                return;
            }
            default:
                cout << "\n\nInvalid choice\n\n" << endl;
        }
    }
}


template<class T>
T* App::takeLoginInput(vector<T*>& users) {
    while (true) {
        string email, password;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password;

        T* user = doLogin<T>(email, password, users);

        if (user) {
            cout << "Login successful" << endl;
            return user;
        }
        cout << "Login failed" << endl;
    }
}

