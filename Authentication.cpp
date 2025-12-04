#include "Authentication.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"


Authentication::Authentication(IUserRepository* repository)
	: usersRepository(repository)
{

}

User* Authentication::Login(const std::string& username, const std::string& password)
{
	User* user = usersRepository->authenticate(username, password);
	if (!user)
		return nullptr;

	auto role = usersRepository->getRole(user->id);

	if (role.size() == 0)
		return nullptr;

	if (role == "admin")
		return new Admin(user->id, user->firstName, user->lastName);

	if (role == "teacher")
		return new Teacher(user->id, user->firstName, user->lastName);

	if (role == "student")
		return new Student(user->id, user->firstName, user->lastName);

	return nullptr;

}