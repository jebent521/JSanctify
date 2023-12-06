// Sanctify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Util.h"

using namespace std;
int main()
{
    queue<string> result;
    result = query(5, "select * from Users");
    while (!result.empty()) {
        cout << result.front() << endl;;
        result.pop();
    }
}


