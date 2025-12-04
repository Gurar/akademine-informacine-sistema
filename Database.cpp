#include "Database.h"
#include <iostream>

Database::Database(std::string host, std::string username, std::string password, std::string dbName)
{
	{
		try {
			sql::Driver* driver = get_driver_instance();
			connection = driver->connect(host, username, password);
			connection->setSchema(dbName);
			std::cout << "Connected" << std::endl;
		}
		catch (sql::SQLException& e) {
			connection = nullptr;
			std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
		}
	}
}

sql::Connection* Database::GetConnection()
{
	return connection;
}