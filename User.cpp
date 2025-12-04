#include "User.h"

User::User() : id(0), firstName(""), lastName(""), role("") {}

User::User(int id, std::string firstName, std::string lastName, std::string role)
	: id(id), firstName(firstName), lastName(lastName), role(role){}

User::User(int id, std::string firstName, std::string lastName, std::string role, std::string groupName)
	: id(id), firstName(firstName), lastName(lastName), role(role), groupName(groupName) {
}

User::~User() {}

bool User::IsValid() const
{
	return id != 0;
}