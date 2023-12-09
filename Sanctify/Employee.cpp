// Employee.cpp contains the implementation the Employee class
#include <iostream>
#include "Employee.h"
#include "Util.h"
using namespace std;
Employee::Employee(string un, string name)
{
	username = un;
	firstName = name;
}

void Employee::mainMenu()
{
	cout << "Hello " << firstName << "! Welcome back to Sanctify." << endl;
	cout << "What would you like to do?" << endl;
	cout << "  1) Browse content by category" << endl;
	cout << "  2) View your praylists" << endl;
	cout << "  3) Search content" << endl;
	cout << "  4) View your profile" << endl;
	cout << "  5) Logout" << endl;
	cout << "  6) Quit" << endl;
	int selection = inputValueBetween(1, 6);
	cout << "Sorry, we haven't implemented that option yet. Bye!" << endl;
	switch (inputValueBetween(1, 6))
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
		viewProfile();
		break;
	case 5:
		logout();
		break;
	case 6:
		exit(0);
		break;
	default:
		throw runtime_error("How did we get here?!?!\n");
		break;
	}
}






