#pragma once
#include <string>

class Grade
{
public:
	int id;
	int number;
	std::string type;


	Grade();
	Grade(int id, const std::string& type);
	Grade(int id, int number, const std::string& type);
};