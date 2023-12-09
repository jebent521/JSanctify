#pragma once
#include <string>
#include "User.h"

class Admin : public Employee {
public:
	Admin(std::string un);
	void mainMenu();
private:
	std::string username;
};