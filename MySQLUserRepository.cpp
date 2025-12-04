#include "MySQLUserRepository.h"
#include <iostream>

MySQLUserRepository::MySQLUserRepository(Database* db)
    : currentDb(db) {
}

std::vector<User*> MySQLUserRepository::getAll()
{

    std::cout << "get all" << std::endl;

    std::vector<User*> users;

    auto connection = currentDb->GetConnection();

    if (!connection)
        return users;

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "SELECT u.id, u.first_name, u.last_name, r.name AS role, g.name AS group_name "
            "FROM users u "
            "LEFT JOIN users_role ur ON u.id = ur.users_id "
            "LEFT JOIN role r ON ur.roles_id = r.id "
            "LEFT JOIN group_students gs ON u.id = gs.user_id "
            "LEFT JOIN groups g ON gs.group_id = g.id "
            "ORDER BY u.id"
        )
    );

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        users.push_back(
            new User(
                res->getInt("id"),
                res->getString("first_name"),
                res->getString("last_name"),
                res->getString("role"),
                res->isNull("group_name") ? "" : res->getString("group_name")
            )
        );
    }

    return users;


}

int MySQLUserRepository::add(User* user)
{
    auto connection = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "INSERT INTO users (first_name, last_name) VALUES (?, ?)"
        )
    );

    stmt->setString(1, user->firstName);
    stmt->setString(2, user->lastName);

    stmt->executeUpdate();

    std::unique_ptr<sql::PreparedStatement> stmt2(
        connection->prepareStatement("SELECT LAST_INSERT_ID();")
    );

    std::unique_ptr<sql::ResultSet> res(stmt2->executeQuery());
    if (res->next())
        return res->getInt(1);

    return -1; // error
}

void MySQLUserRepository::update(User* user)
{
    auto con = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "UPDATE users SET first_name=?, last_name=? WHERE id=?"
        )
    );

    stmt->setString(1, user->firstName);
    stmt->setString(2, user->lastName);
    stmt->setInt(3, user->id);
    stmt->executeUpdate();

    std::unique_ptr<sql::PreparedStatement> roleStmt(
        con->prepareStatement("SELECT id FROM role WHERE name=? LIMIT 1;")
    );

    roleStmt->setString(1, user->role);
    auto roleRes = std::unique_ptr<sql::ResultSet>(roleStmt->executeQuery());

    if (!roleRes->next()) {
        return;
    }

    int roleId = roleRes->getInt("id");

    std::unique_ptr<sql::PreparedStatement> clearStmt(
        con->prepareStatement("DELETE FROM users_role WHERE user_id=?")
    );

    clearStmt->setInt(1, user->id);
    clearStmt->executeUpdate();

    assignRole(user->id, roleId);

}

void MySQLUserRepository::remove(int id)
{
    try {

        auto con = currentDb->GetConnection();

        std::unique_ptr<sql::PreparedStatement> stmt(
            con->prepareStatement("DELETE FROM users_role WHERE users_id = ?")
        );
        stmt->setInt(1, id);
        stmt->executeUpdate();

        std::unique_ptr<sql::PreparedStatement> stmtUser(
            con->prepareStatement("DELETE FROM users WHERE id = ?")
        );

        stmtUser->setInt(1, id);

        stmtUser->executeUpdate();
    }
    catch (sql::SQLException& e)
    {
        throw std::runtime_error(
            "MySQL Error: " + std::string(e.what())
        );
    }
}

User* MySQLUserRepository::authenticate(const std::string& username, const std::string& password)
{

    auto connection = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "SELECT id, first_name, last_name "
            "FROM users WHERE first_name=? AND last_name=? LIMIT 1;"
        )
    );

    stmt->setString(1, username);
    stmt->setString(2, password);

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    if (!res->next())
        return nullptr;

    return new User(
        res->getInt("id"),
        res->getString("first_name"),
        res->getString("last_name"),
        ""
    );

}

std::string MySQLUserRepository::getRole(int userId)
{
    auto connection = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "SELECT d.name AS role "
            "FROM users_role ud "
            "JOIN role d ON ud.roles_id = d.id "
            "WHERE ud.users_id = ? "
            "LIMIT 1;"
        )
    );

    stmt->setInt(1, userId);

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    if (res->next()) {
        return res->getString("role");
    }

    return "";
}

std::vector<std::string> MySQLUserRepository::getAllRoles()
{
    auto connection = currentDb->GetConnection();

    std::vector<std::string> roles;

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "SELECT * FROM Role"
        )
    );

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        roles.push_back(res->getString("role"));
    }

    return roles;
}

void MySQLUserRepository::assignRole(int userId, int roleId)
{
    auto connection = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "INSERT INTO users_role (users_id, roles_id) VALUES (?, ?)"
        )
    );

    stmt->setInt(1, userId);
    stmt->setInt(2, roleId);
    stmt->executeUpdate();
}

bool MySQLUserRepository::isStudentInAnyGroup(int userId)
{
    auto connection = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "SELECT COUNT(*) AS count FROM group_students WHERE user_id = ?"
        )
    );

    stmt->setInt(1, userId);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    if (res->next())
        return res->getInt("count") > 0;

    return false;
}

bool MySQLUserRepository::isTeacherAssignedToAnySubject(int userId)
{
    auto connection = currentDb->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        connection->prepareStatement(
            "SELECT COUNT(*) AS count FROM subject_teacher WHERE teacher_id = ?"
        )
    );

    stmt->setInt(1, userId);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    if (res->next())
        return res->getInt("count") > 0;

    return false;
}

