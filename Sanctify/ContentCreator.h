#pragma once
#include "User.h"

// ContentCreator.h contains the interface for all objects of type ContentCreator
// It inherits from the generic class User 
class ContentCreator : public User {
public:
	ContentCreator(std::string un, std::string name);
	void mainMenu();
	void uploadContent(); 
	void viewUploadedContent(); 
private:
	std::string username;
	std::string firstName; 
};
