// User.h contains the interface for all objects of generic type User.
#pragma once

class User {
public:
	User();
	User(std::string un, std::string fn);
	void startMenu();
	void login();
	void signUp();
	//void forgotPassword(); // if we get around to it
	void browseContent();
	void viewPraylists();
	void searchContent();
	void viewProfile();
	void logout();
protected:
	std::string username;
	std::string firstName;
};