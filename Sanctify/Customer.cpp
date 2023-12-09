// Customer.cpp contains the implementation the Customer class
#include <iostream>
#include <string>
#include "Customer.h"
#include "Util.h"
using namespace std;

Customer::Customer(string uid, string name, bool iP)
{
	username = uid;
	firstName = name;
	isPaid = iP;
}
void Customer::mainMenu()
{
	cout << "Hello " << firstName << "! Welcome back to Sanctify." << endl;
	cout << "What would you like to do?" << endl;
	cout << "  1) Browse content by category" << endl;
	cout << "  2) View your praylists" << endl;
	cout << "  3) Search content" << endl;
	cout << "  4) View your profile" << endl;
	cout << "  5) Logout" << endl;
	cout << "  6) Quit" << endl;
	switch (inputValueBetween(1,6))
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
		cout << "How did we get here?!" << endl;
		throw runtime_error("Invalid selection. You've broken out of the matrix");
	}
}
