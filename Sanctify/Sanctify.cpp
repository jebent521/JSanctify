// testProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Util.h"
using namespace std;
int main()
{
    Util thingy;
    vector<string> persons = thingy.executeQuery("SELECT * FROM Persons", 5, "", "");
    for (int i = 0; i < persons.size(); i++) {
        cout << persons.at(i) << endl;
    }
}


