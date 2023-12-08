/* Util.cpp contains the implementation for Util.h */

#include <iostream>
#include <queue>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdexcept>
#include <vector> // just trust me on this
#include "Util.h"



using namespace std;

void showSQLError(unsigned int handleType, const SQLHANDLE& handle)
{
    SQLCHAR SQLState[1024];
    SQLCHAR message[1024];
    if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
        // Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
        cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
}

void demoQuery() {
    vector<string> result;
    result = query(5, "select * from Users");
    for (string i : result) {
        cout << i << endl;
    }
}


// don't bother understanding it, just follow the comments to use it
// CREDIT GOES TO TYLER DEAN FOR WRITING THIS FUNCTION (but we modified it slightly)
vector<string> query(int numOfItems, string inputQuery) {

    SQLHANDLE SQLEnvHandle = NULL;
    SQLHANDLE SQLConnectionHandle = NULL;
    SQLHANDLE SQLStatementHandle = NULL;
    SQLRETURN retCode = 0;
    const char* SQLQuery = inputQuery.c_str();
    vector<string> result;

    do {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
            // Allocates the environment
            break;

        if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
            // Sets attributes that govern aspects of environments
            break;

        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
            // Allocates the connection
            break;

        if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
            // Sets attributes that govern aspects of connections
            break;

        SQLCHAR retConString[1024]; // Conection string
        switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=EngSQL01.franciscan.edu, 1433; DATABASE=Sanctify; UID=SanctifyJCETAdmin; PWD=LetsGetDerpy-123$;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
            // Establishes connections to a driver and a data source
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
            // Allocates the statement
            break;

        if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
            // Executes a preparable statement
            showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
            break;
        }
        else {
            char name[256];
            //char dept_name[256];
            while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
                // Fetches the next rowset of data from the result

                for (int i = 1; i <= numOfItems; i++) {
                    SQLGetData(SQLStatementHandle, i, SQL_C_DEFAULT, &name, sizeof(name), NULL);
                    result.push_back(name);
                }
            }
        }
    } while (FALSE);

    SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

    return result;
}
/*  Prompts the user for a string input (e.g. username, password, etc.)
    May or may not implement validity checking (time-dependent)
    Returns a valid string  */
std::string getString(string prompt)
{
    string input;
    bool isValid = false;
    do {
        cout << prompt;
        cin >> input;
        /*
        if (string is valid) {
            isValid = true;
        } else {
            cout << "  Please enter a valid input." << endl;
        }
        */
        isValid = true; // for the time being, while we haven't yet implemented validity-checking
    } while (!isValid);
    return input;
}


bool passwordCheck(string pw) {
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool special = false;

    if (pw.length() < 12) {
        return false;
    }

    for (int i = 0; i < pw.length(); i++) {


    }




    return upper && lower && number && special;
}

int inputValueBetween(int low, int high)
{
    // check if arguments are valid
    if (low > high) {
        throw invalid_argument("low must be less than high");
    }
    int intput;
    string input;
    do {
        cout << "Selection: ";      // prompt user for input
        cin >> input;
        try                         // try to convert it to an integer
        {
            intput = stoi(input);
        }
        catch (const std::invalid_argument&)
        {                           // if unsuccessful, yell at user and try again
            cout << "  Invalid input. Please enter a number between " << low << " and " << high << "." << endl;
            continue;
        }
        if (intput >= low && intput <= high)
        {                           // if successful and input is within range, get out of the loop 
            break;
        }
        cout << "  Invalid input. Please enter a number between " << low << " and " << high << " (inclusive)." << endl;
    } while (true);                 // continue looping until input is valid
    // input is valid, so return it
    return intput;
}


