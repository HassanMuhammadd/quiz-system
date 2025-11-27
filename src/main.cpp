#include <iostream>
#include "App.h"

using namespace std;

int main(){
	App app;

	Admin* admin = new Admin("a", "a", "a");

	app.run();

	return 0;
}