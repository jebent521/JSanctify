#pragma once
#include <string>
#include "User.h"

class Admin : public User {
public:
	Admin(std::string un);
	void mainMenu();
private:
	std::string username;
};