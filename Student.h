#pragma once
#include "User.h"

class Student : public User
{
public:
	Student();
	Student(int id, const std::string& firstName, const std::string& lastName);
};