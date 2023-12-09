#include <iostream>
#include <string>
#include "Admin.h"
#include "Util.h"
using namespace std;

Admin::Admin(string un, string fn) : Employee(un, fn)
{
}

void Admin::mainMenu()
{
	bool exiting = false;
	do 
	{
		cout << "Hello" << firstName << "! Welcome back to Sanctify." << endl;
		cout << "What would you like to do?" << endl;
		cout << " 1) Browse content by category" << endl;
		cout << " 2) View your praylists" << endl;
		cout << " 3) Search content" << endl;
		cout << " 4) View users' profiles" << endl;
		cout << " 5) View employees' profiles" << endl;
		cout << " 6) Add new employee" << endl;
		cout << " 7) Add new content creator" << endl;
		cout << " 8) View your profile" << endl;
		cout << " 9) Logout" << endl;
		cout << " 10) Quit" << endl;
		switch (inputValueBetween(1, 10)) {
		case 1:
			browseContent();
			break;
		case 2:
			viewPraylists();
			break;

		case 3:
			searchContent();
			break;
		case 4:
			viewUser();
			break;
		case 5:
			viewEmployee();
			break;
		case 6:
			addEmployee();
			break;
		case 7:
			addContentCreator();
			break;
		case 8:
			viewProfile();
			break;
		case 9:
			exiting = true;
			logout();
			break;
		case 10:
			exiting = true;
			exit(0);
			break;
		default:
			cout << "How did we get here?!" << endl;
			throw runtime_error("Invalid selection. You've broken out of the matrix");
		}
	} while (!exiting);
}

void Admin::viewUser() {
	notImplemented();
}

void Admin::viewEmployee() {
	notImplemented();
}

void Admin::addEmployee() {
	notImplemented();
}

void Admin::addContentCreator() {
	notImplemented();
}

