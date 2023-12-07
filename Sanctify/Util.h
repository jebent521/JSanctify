/* Util.h contains the interface for all Utilities (functions that any class or program can use) */

#pragma once
#include <string>
#include <queue>

// This is the function that allows the app to talk to the database
// It inputs the excpected number of columns (could be 0 for inserts and deletes)
// and a string of the query that it runs
std::queue<std::string> query(int col, std::string query);

// This demonstrates how to use query() for documentation purposes
void demoQuery();

// Whoever wrote this should tell us what it's doing
bool passwordCheck(std::string pw);

// This is a quick way of getting user input
// It reads user's input, checks if it is valid,
// and returns the selection as an integer.
// Use this so you don't have to write all new code.
int inputIntSelection(int low, int high);
