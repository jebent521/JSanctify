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
	cout << "__________________________" << endl;

}

void User::login() {
	cout << "Please enter:\n" << endl;
	cout << "name:" << endl;
	//cin >> name\n
	cout << "password:" << endl;
	//send to appropriate main menu (depending on role)
}

void User::signUp() {
	cout << "Thank you for signing up! We are glad to have you on board!\n" << endl;
	cout << "Please enter the following information:\n" << endl;
	cout << "Username:" << endl;
	//cin >> Username
	cout << "Password:" << endl;
	//cin >> Password
	cout << "Email:" << endl;
	//cin >> Email
	cout << "First Name:" << endl;
	//cin << First Name:
	cout << "Last Name:" << endl;
	//cin << Last Name:
}

void User::forgotPassword() {
	cout << "Please enter your email:" << endl;
	//cin >> Email

}

void User::freeUserMenu() {

}

void User::paidUserMenu() {

}

void User::contentCreatorMenu() {

}

void User::employeeMainMenu() {

}

void User::adminMainMenu() {

}