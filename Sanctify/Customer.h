// Customer.h contains the interface for all objects of type Customer.
// It inherits from the generic class User
#pragma once
#include "User.h"
class Customer : public User {
public:
	Customer(std::string username, std::string firstName, bool isPaid);
	void mainMenu();
private:
	std::string username;
	std::string firstName;
	bool isPaid;
};