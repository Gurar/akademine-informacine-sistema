#pragma once
#include "IRepository.h"
#include "User.h"
#include <string>

class IUserRepository : public IRepository<User>
{
public:
	virtual User* authenticate(const std::string& username, const std::string& password) = 0;
	virtual std::string getRole(int userId) = 0;
	virtual std::vector<std::string> getAllRoles() = 0;
	virtual void assignRole(int userId, int roleId) = 0;

	virtual bool isStudentInAnyGroup(int userId) = 0;
	virtual bool isTeacherAssignedToAnySubject(int userId) = 0;
};