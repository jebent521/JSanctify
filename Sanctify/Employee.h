// Employee.h contains the interface for all objects of type Employee.
// It inherits from the generic class User
#pragma once
#include <string>
#include "User.h"

class Employee : public User {
public:
	Employee(std::string un, std::string fn);
	Employee();
	void mainMenu();
private:
	std::string username;
};