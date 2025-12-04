#pragma once
#include "IRoleRepository.h"
#include "Database.h"

class MySQLRoleRepository : public IRoleRepository
{
private:
    Database* db;

public:
    MySQLRoleRepository(Database* db);
    std::vector<Role*> getAllRoles() override;
};