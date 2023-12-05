#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <vector>
#include <string>
class Util {
public:
	std::vector<std::string> executeQuery(const char* query, unsigned int cols, const char* uid, const char* pwd);
private:
	void showSQLError(unsigned int handleType, const SQLHANDLE& handle);
};