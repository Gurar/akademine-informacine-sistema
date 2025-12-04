#pragma once
#include "IUserRepository.h"
#include "User.h"
class Authentication
{
private:
	IUserRepository* usersRepository;

public:
	Authentication(IUserRepository* repository);

	User* Login(const std::string& username, const std::string& password);
};