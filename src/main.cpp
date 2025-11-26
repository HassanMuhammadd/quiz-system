#include <iostream>
#include "App.h"

using namespace std;

int main(){
	App app;

	Admin* admin = new Admin("admin", "admin", "admin");

	app.run();

	return 0;
}