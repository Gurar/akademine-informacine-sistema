#pragma once
#include <string>
class Subject
{
public:
	int id;
	std::string name;
	int creditId;
	int creditNumber;
	std::string groupName;
	std::string teacherName;
	
	Subject(int id, const std::string& name, int creditId, int creditNumber);

	Subject(int id, const std::string& name, int creditId, int creditNumber, const std::string& groupName);

	Subject(int id, const std::string name, int creditNumber, std::string groupName);

	Subject(int id, const std::string& name, int creditId, int creditNumber, const std::string& groupName, const std::string& teacherName);

};