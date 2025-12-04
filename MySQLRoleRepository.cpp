#include "MySQLRoleRepository.h"

MySQLRoleRepository::MySQLRoleRepository(Database* db)
    : db(db) {
}

std::vector<Role*> MySQLRoleRepository::getAllRoles()
{
    std::vector<Role*> roles;

    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT id, name FROM role ORDER BY name ASC"
        )
    );

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    while (res->next())
    {
        roles.push_back(
            new Role(
                res->getInt("id"),
                res->getString("name")
            )
        );
    }

    return roles;
}