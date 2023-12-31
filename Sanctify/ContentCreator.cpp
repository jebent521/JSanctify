#include <iostream>
#include <string>
#include "ContentCreator.h"
#include "Util.h"
using namespace std;

ContentCreator::ContentCreator(string un, string name)
{
	username = un;  
	firstName = name; 
}

void ContentCreator::mainMenu()
{
	cout << "\nHello " << firstName << "! Welcome back to Sanctify." << endl;
	cout << "You are a content creator." << endl;
	bool exiting = false;
	do 
	{
		cout << "\nWhat would you like to do?" << endl;
		cout << " 1) Browse content by category" << endl;
		cout << " 2) View your praylists" << endl;
		cout << " 3) Search content" << endl;
		cout << " 4) Upload content" << endl;
		cout << " 5) View your uploaded content" << endl;
		cout << " 6) View your profile" << endl;
		cout << " 7) Logout" << endl;
		cout << " 8) Quit" << endl;
		switch (inputValueBetween(1, 8)) {
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
			uploadContent();
			break;
		case 5:
			viewUploadedContent();
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
			exit(0); // quit 
			break;
		default:
			throw runtime_error("How did we get here?!?!\n");
			break;
		}
	} while (!exiting);
}

void ContentCreator::uploadContent() {
	notImplemented();
}

void ContentCreator::viewUploadedContent() {
	notImplemented();
}

