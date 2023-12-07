// User.cpp contains the implementation the User class
#include <iostream>
#include "User.h"
#include "Util.h"
using namespace std;

void User::startMenu() {
	cout << "Welcome to Sanctify!\n" << endl;
	cout << "What would you like to do?" << endl;
	cout << "  1) Login" << endl;
	cout << "  2) Sign up" << endl;
	cout << "  3) Exit" << endl;
	cout << "--------------------------" << endl;
	switch (inputValueBetween(1,3))
	{
	case 1:
		login();
		break;
	case 2:
		signUp();
		break;
	case 3:
		cout << "Hope to see you soon!" << endl;
		exit(0);
		break;
	default:
		throw runtime_error("How did we get here?!?!\n");
		break;
	}

}

void User::login() {
	cout << "Logging in..." << endl;
}

void User::signUp() {
	string username;
	string passward = "";

	cout << "Enter new Username: ";

	while (true) {
		username;

	}
}