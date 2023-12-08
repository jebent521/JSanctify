// User.cpp contains the implementation the User class
#include <iostream>
#include <vector>
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
	cout << "Please enter:" << endl;
	string userName;
	userName = inputString("Username: ");
	string password;
	password = inputString("Password: ");
	vector<string> loginCheck = query(2, "select username from users where username = '" + userName + "' and password = '" + password + "' ");
	cout << "you entered:" << endl;
	cout << userName << endl;
	cout << password << endl;

	//send to appropriate main menu (depending on role)
}

void User::signUp() {
	cout << "Thank you for signing up! We are glad to have you on board!\n" << endl;
	cout << "Please enter the following information:" << endl;
	string username;
	string password;
	string email;
	string firstName;
	string lastName;
	do {	// input username
		username = inputString("Username: ");
		vector<string> usernameCheck = query(1, "select username from Users where username = '" + username + "';");
		if (usernameCheck.empty()) break;
		else cout << "  Username already taken. Please try a different one." << endl;
	} while (true);
	do {	// input password
		password = inputString("Password: ");
		if (passwordCheck(password)) break;
		else cout << "  Password must contain...";
	} while (true);
	do {	// input email
		email = inputString("Email address: ");
		// check if valid email
	} while (true);
	firstName = inputString("First name: ");
	lastName = inputString("Last name: ");


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
