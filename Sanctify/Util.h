/* Util.h contains the interface for all Utilities (functions that any class or program can use) */

#pragma once
#include <string>
#include <vector>

/*	This is the function that allows the app to talk to the database
	It inputs the excpected number of columns (could be 0 for inserts and deletes) and a string of the query that it runs
	Returns a vector of the results	*/
std::vector<std::string> query(int col, std::string query);


// This demonstrates how to use query() for documentation purposes
void demoQuery();

/*	Verifies that the input is a valid password
	Returns true if the password contains:
		at least 8 characters,
		one uppercase, 
		one lowercase,
		one special character, 
		one number	*/
bool passwordCheck(std::string pw);

/*	This is a quick way of getting user input
	It reads user's input, checks if it is valid, and returns the selection as an integer.
	Use this so you don't have to write all new code.*/
int inputValueBetween(int low, int high);

std::string getString(std::string input);
