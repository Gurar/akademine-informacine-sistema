#pragma once
#include <string>
class Role
{
public:
	int id;
	std::string name;

	Role(int id, const std::string& name);
};