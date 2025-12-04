#pragma once
#include "User.h"

class Admin : public User
{
public:
	Admin();

	Admin(int id, const std::string& firstName, const std::string& lastName);
};