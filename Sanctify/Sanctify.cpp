// testProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"
using namespace std;
int main()
{
    queue<string> result;
    //Util thingy;
    //vector<string> persons = thingy.executeQuery("SELECT * FROM Persons where userID = ", 5, "", "");
    result = query(2, "select firstName, lastName from Persons");
    while (!result.empty()) {
        cout << result.front() << endl;;
        result.pop();
    }
}


