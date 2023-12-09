#pragma once
#include <string>
#include "Employee.h"

class Admin : public Employee {
public:
	Admin(std::string un, std::string fn);
	void mainMenu();
private:
	std::string username;
	std::string firstName;
};