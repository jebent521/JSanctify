#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <string>
#include <vector>
#include "Util.h"
using namespace std;

void Util::showSQLError(unsigned int handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
		// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
		cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
}

vector<string> Util::executeQuery(const char* query, unsigned int cols, const char* uid, const char* pwd)
{
	vector<string> retVect;
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	//char SQLQuery[] = query;

	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment... breaks if unsuccessful
			break;

		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments... breaks if unsuccessful
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
			// Allocates the connection... breaks if unsuccessful
			break;

		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections... breaks if unsuccessful
			break;

		SQLCHAR retConString[1024]; // Conection string
		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=EngSQL01.franciscan.edu, 1433; DATABASE=Sanctify; UID=SanctifyJCETAdmin; PWD=LetsGetDerpy-123$;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			// Establishes connections to a driver and a data source... tests output
		case SQL_SUCCESS:
			break;
		case SQL_SUCCESS_WITH_INFO:
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
			// Allocates the statement... breaks if unsuccessful
			break;

		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)query, SQL_NTS)) { // this is the part that executes the query
			// Executes a preparable statement... shows error and breaks if unsuccessful
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else { // processes the output of the query
			int PersonID;
			char lastName[255];
			char firstName[255];
			char address[255];
			char city[255];
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
				/*
				// Fetches the next rowset of data from the result
				// handle, row, data type, variable to store it in, size of variable, NULL
				SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &PersonID, sizeof(PersonID), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &lastName, sizeof(lastName), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &firstName, sizeof(firstName), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &city, sizeof(city), NULL);
				// Retrieves data for a single column in the result set... one getData line for each column
				cout << PersonID << "\t" << lastName << "\t" << firstName << "\t" << address << "\t" << city << endl;
				*/
				for (int i = 1; i <= cols; i++) {
					string entry = "";
					SQLGetData(SQLStatementHandle, i, SQL_C_DEFAULT, &entry, sizeof(entry), NULL);
					retVect.push_back(entry);
				}
			}
		}
	} while (FALSE); // you might be thinking to yourself... "while false?! that only runs it once!", and you're right.
	// the while (FALSE) allows you to break out of the loop construct if it runs into an error (see the breaks above)

	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	// Frees the resources and disconnects
	return retVect;	
}