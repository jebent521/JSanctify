// Employee.cpp contains the implementation the Employee class
#include <iostream>
#include "Employee.h"
#include "Util.h"
using namespace std;
Employee::Employee(string un, string fn) : User(un, fn) {}

void Employee::mainMenu()
{
	cout << "Hello " << firstName << "! Welcome back to Sanctify." << endl;
	cout << "You are an employee" << endl;
	bool exiting = false;
	do {

		cout << "What would you like to do?" << endl;
		cout << "  1) Browse content by category" << endl;
		cout << "  2) View your praylists" << endl;
		cout << "  3) Search content" << endl;
		cout << "  4) View users' profiles" << endl;
		cout << "  5) Add new content creator" << endl;
		cout << "  6) View your profile" << endl;
		cout << "  7) Logout" << endl;
		cout << "  8) Quit" << endl;
		switch (inputValueBetween(1, 8))
		{
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
			viewUserProfiles();
			break;
		case 5:
			addContentCreator();
			break;
		case 6:
			viewProfile();
			break;
		case 7:
			exiting = true;
			logout();
			break;
		case 8:
			exiting = true;
			exit(0);
			break;
		default:
			throw runtime_error("How did we get here?!?!\n");
			break;
		}
	} while (!exiting);
}

void Employee::viewUserProfiles()
{
	notImplemented();
}

void Employee::addContentCreator()
{
	notImplemented();
}
