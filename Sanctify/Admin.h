#pragma once
#include <string>
#include "Employee.h"

class Admin : public Employee {
public:
	Admin(std::string un, std::string fn);
	void mainMenu();
	void viewUser(); 
	void viewEmployee(); 
	void addEmployee(); 
	void addContentCreator(); 
};