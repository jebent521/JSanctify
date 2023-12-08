// Customer.h contains the interface for all objects of type Customer.
// It inherits from the generic class User
#pragma once
#include "User.h"
class Customer : public User {
public:
	Customer(std::string username, bool isPaid);
private:
	std::string username;
	bool isPaid;
};