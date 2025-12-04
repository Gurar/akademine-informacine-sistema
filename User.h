#pragma once
#include <string>
class User
{
public:
	int id;
	std::string firstName;
	std::string lastName;
	std::string role;
	std::string groupName;

	User();

	User(int id, std::string firstName, std::string lastName, std::string role);

	User(int id, std::string firstName, std::string lastName, std::string role, std::string groupName);

	virtual ~User();

	bool IsValid() const;
};