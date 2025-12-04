#pragma once
#include "User.h"

class Teacher : public User
{
public:
	Teacher();
	Teacher(int id, const std::string& firstName, const std::string& lastName);
};