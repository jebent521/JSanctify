#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <vector>
#include <string>
#include <queue>
/*class Util {
public:
	std::vector<std::string> executeQuery(unsigned int cols, const char* query);
private:
	void showSQLError(unsigned int handleType, const SQLHANDLE& handle);
};*/

std::queue<std::string> query(int col, std::string query);
