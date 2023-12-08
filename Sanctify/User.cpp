// User.cpp contains the implementation the User class
#include <iostream>
#include <vector>
#include "Util.h"
#include "User.h"
#include "Customer.h"
#include "Admin.h"
#include "Employee.h"
#include "ContentCreator.h"
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
	string password;
	
	do {	//input username and password - check: does user exist?
		userName = inputString("Username: ");
		password = inputString("Password: ");
		vector<string> loginCheck = query(2, "select username from users where username = '" + userName + "' and password = '" + password + "' ");
		if (loginCheck.empty())
			cout << "Invalid username or password" << endl;
		else break;
	} while (true);

	//send to appropriate main menu (depending on role)
	//user exists, what type of user is (s)he?
	vector<string> userQuery = query(2, "select username, sub_type from Customer where username = '" + userName + "'");
	if (!userQuery.empty()) {	// if user is in customer table
		if (userQuery.at(1).compare("paid") == 0) {	// and sub_type == paid
			Customer currentUser = Customer(userName, 1);	// create a paid customer
			currentUser.mainMenu();
		}
		else {
			Customer currentUser = Customer(userName, 0);	// otherwise create a free customer
			currentUser.mainMenu();
		}
	}
	else {
		userQuery = query(2, "select username, role from Employee where username = '" + userName + "'");
		if (!userQuery.empty()) {	// if user is in Employee table
			if (userQuery.at(1).compare("admin") == 0) {	// and role == admin
				Admin currentUser = Admin(userName);	// create an admin
				currentUser.mainMenu();
			}
			else {
				Employee currentUser = Employee(userName);	// otherwise create a regular employee
				currentUser.mainMenu();
			}
		}
		else {
			userQuery = query(1, "select username from ContentCreator where username = '" + userName + "'");
			if (!userQuery.empty()) {	// if user is in ContentCreator table
				ContentCreator currentUser = ContentCreator(userName);	// create a ContentCreator
				currentUser.mainMenu();
			}
			else {
				cout << "Your account is present in the DB but not assigned a role" << endl;
				throw runtime_error("Username is not assigned a role.\n");
			}
		}
	}

	/*
	cout << "you entered:" << endl;
	cout << userName << endl;
	cout << password << endl;
	*/
}

//if (!query(2, "select... from.. where...).empty()) {....}
//else if (!query(2, "select... from.. where...).empty()) {....}
//else if (!query(2, "select... from.. where...).empty()) {....}
//else throw funny error - u dont exist

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
		if (usernameCheck.empty()) break;	// username isn't taken
		else cout << "  Username already taken. Please try a different one." << endl;
	} while (true);
	do {	// input password
		password = inputString("Password: ");
		if (passwordCheck(password)) break;	// password is valid
		else {
			cout << "  Password must contain at least 8 characters, one uppercase, one lowercase, one special character, one number." << endl;
		}
	} while (true);
	do {	// input email
		email = inputString("Email address: ");
		// check if valid email
	} while (true);
	firstName = inputString("First name: ");
	lastName = inputString("Last name: ");


}
