#pragma once
#include "IUserRepository.h"
#include "Database.h"
#include <string>
class MySQLUserRepository : public IUserRepository
{
private:
    Database* currentDb;
public:
    MySQLUserRepository(Database* db);
    std::vector<User*> getAll() override;
    int add(User* user) override;
    void update(User* user) override;
    void remove(int id) override;
    User* authenticate(const std::string& username, const std::string& password) override;
    std::string getRole(int userId) override;
    std::vector<std::string> getAllRoles() override;
    void assignRole(int userId, int roleId) override;
    bool isStudentInAnyGroup(int userId) override;
    bool isTeacherAssignedToAnySubject(int userId) override;
};