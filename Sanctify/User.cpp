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

User::User()
{
}

User::User(std::string un, std::string fn)
{
	username = un;
	firstName = fn;
}

void User::startMenu() {
	do {
		cout << "Welcome to Sanctify!" << endl;
		cout << "What would you like to do?" << endl;
		cout << "  1) Login" << endl;
		cout << "  2) Sign up" << endl;
		cout << "  3) Exit" << endl;
		switch (inputValueBetween(1, 3))
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
	} while (true);
}


void User::login() {
	cout << "Please enter your credentials." << endl;
	string userName;
	string password;
	string firstName;
	
	do {	//input username and password - check: does user exist?
		userName = inputString("Username: ");
		password = inputString("Password: ");
		vector<string> loginCheck = query(3, "select username, password, first_name from Users where username = '" + userName + "' and password = '" + password + "' ");
		if (loginCheck.empty())
			cout << "Invalid username or password" << endl;
		else {
			firstName = loginCheck.at(2);
			break;
		}
	} while (true);

	//send to appropriate main menu (depending on role)
	//user exists, what type of user is (s)he?
	vector<string> userQuery = query(2, "select username, sub_type from Customer where username = '" + userName + "'");
	if (!userQuery.empty()) {	// if user is in customer table
		if (userQuery.at(1).compare("paid") == 0) {	// and sub_type == paid
			Customer currentUser = Customer(userName, firstName, 1);	// create a paid customer
			currentUser.mainMenu();
		}
		else {
			Customer currentUser = Customer(userName, firstName, 0);	// otherwise create a free customer
			currentUser.mainMenu();
		}
	}
	else {
		userQuery = query(2, "select username, role from Employee where username = '" + userName + "'");
		if (!userQuery.empty()) {	// if user is in Employee table
			if (userQuery.at(1).compare("admin") == 0) {	// and role == admin
				Admin currentUser = Admin(userName, firstName);	// create an admin
				currentUser.mainMenu();
			}
			else {
				Employee currentUser = Employee(userName, firstName);	// otherwise create a regular employee
				currentUser.mainMenu();
			}
		}
		else {
			userQuery = query(1, "select username from ContentCreator where username = '" + userName + "'");
			if (!userQuery.empty()) {	// if user is in ContentCreator table
				ContentCreator currentUser = ContentCreator(userName, firstName);	// create a ContentCreator
				currentUser.mainMenu();
			}
			else {
				cout << "Your account is present in the DB but not assigned a role" << endl;
				throw runtime_error("Username is not assigned a role.\n");
			}
		}
	}
}

void User::signUp() {
	cout << "Thank you for signing up! We are glad to have you on board!\n" << endl;
	cout << "Please enter the following information:" << endl;
	string username;
	string password;
	string email;
	string firstName;
	string lastName;
	int paidSelection;
	bool isPaid = false;
	string confirmation;
	bool confirmed = false;
	do {
		do {	// input username
			username = inputString("Username: ");
			vector<string> usernameCheck = query(1, "select username from Users where username = '" + username + "';");
			if (usernameCheck.empty()) break;	// username isn't taken
			else cout << "  Username already taken. Please try a different one." << endl;
		} while (true);
		do {	// input password
			password = inputString("Password: ");
			if (passwordCheck(password)) break;	// password is valid
			else cout << "  Password must contain at least 8 characters, one uppercase, one lowercase, one special character, one number." << endl;
		} while (true);
		do {	// input email
			email = inputString("Email address: ");
			if (isEmail(email)) break;
			else cout << "  Not a valid email." << endl;
		} while (true);
		firstName = inputString("First name: ");	// input first name
		lastName = inputString("Last name: ");		// input last name
		cout << "Would you like to sign up for Sanctify Free or Sanctify Plus ($99.99/mo)?" << endl;
		cout << "  1) Sanctify Free" << endl;
		cout << "  2) Sanctify Plus" << endl;
		paidSelection = inputValueBetween(1,2);
		isPaid = (paidSelection == 2);

		cout << "You entered: " << endl;
		cout << "Username:\t\t" <<			username << endl;
		cout << "Password:\t\t" <<			password << endl;
		cout << "Email address:\t\t" <<		email << endl;
		cout << "First name:\t\t" <<		firstName << endl;
		cout << "Last name:\t\t" <<			lastName << endl;
		cout << "Subscription Type:\t" <<	(isPaid ? "Paid" : "Free") << endl;
		confirmation = inputString("Is this correct? (y/n): ");
		confirmed = (confirmation.compare("y") == 0);
	} while (!confirmed);
	cout << "Creating account..." << endl;
	query(0, "insert into Users values ('" + username + "', '" + password + "', '" + email + "', '" + firstName + "', '" + lastName + "');");
	query(0, "insert into Customer values ('" + username + "', '" + ((isPaid ? "paid" : "free")) + "');");
	cout << "Account created!" << endl;
	login();
}

void User::browseContent() {
	//user can view all categories
	vector<string> viewCategories = query(1, "select * from category");
	notImplemented();
}

void User::viewPraylists() {
	//user can view all their praylists
	vector<string> viewPraylists = query(2, "select praylist_name, description from praylist");
	notImplemented();
}

void User::searchContent() {
	//search by name
	cout << "Type in the name of what you're searching for (or 'back' to go back)." << endl;
	string search;
	do { //searches for matches based on user input
		search = inputString("Search: ");
		if (search.compare("back") == 0) return;
		vector<string> searchQuery = query(2, "select content_id, content_name from content where content_name like '%" + search + "%'");
		int vectorSize = searchQuery.size();
		if (searchQuery.empty()) //no results, nothing displays
			cout << "  Sorry no results :(" << endl;
		else { //prints matches to search 
			for (int i = 0; i < vectorSize; i += 2) {
				int number = (i / 2) + 1;
				string name = searchQuery.at(i);
				cout << number << ") " << name << endl;
			}
			int selection = inputValueBetween(1, vectorSize);
		}
	} while (true);
}

void User::viewProfile()
{
	notImplemented();
}

void User::logout()
{
	username = "";
	firstName = "";
	cout << "Logging you out...\n" << endl;
}
