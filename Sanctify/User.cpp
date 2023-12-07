// User.cpp contains the implementation the User class
#include <iostream>
#include "User.h"
#include "Util.h"
using namespace std;

void User::startMenu() {
	/* here is where we list options for what each user can do:
		1. Login
		2. Sign up
		3. Recover account (forgot password!)
	*/
	cout << "Welcome to Sanctify!\n" << endl;
	cout << "What would you like to do?" << endl;
	cout << "  1) Login" << endl;
	cout << "  2) Sign up" << endl;
	cout << "  3) Exit" << endl;
	cout << "__________________________" << endl;
	cout << inputValueBetween(1, 3) << endl;
}

void User::login() {

}

void User::signUp() {
	string username;
	string passward = "";

	cout << "Enter new Username: ";

	while (true) {
		username;

	}
}