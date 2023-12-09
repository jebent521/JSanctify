#pragma once
#include "User.h"
class ContentCreator : public User {
public:
	ContentCreator(std::string un);
	void mainMenu();
private:
	std::string username;
};