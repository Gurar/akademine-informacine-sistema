#pragma once
#pragma once
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <iostream>

class Database
{
public:
	Database(std::string host, std::string username, std::string password, std::string dbName);
	sql::Connection* GetConnection();
private:
	sql::Connection* connection;
};