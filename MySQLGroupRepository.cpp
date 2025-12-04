#include "MySQLGroupRepository.h"
#include <memory>

MySQLGroupRepository::MySQLGroupRepository(Database* db)
    : db(db) {
}

std::vector<Group*> MySQLGroupRepository::getAll()
{
    std::vector<Group*> list;

    auto con = db->GetConnection();
    std::unique_ptr<sql::Statement> stmt(con->createStatement());

    auto res = std::unique_ptr<sql::ResultSet>(
        stmt->executeQuery("SELECT id, name FROM groups")
    );

    while (res->next())
    {
        list.push_back(new Group(
            res->getInt("id"),
            res->getString("name")
        ));
    }

    return list;
}

int MySQLGroupRepository::add(Group* group)
{
    auto con = db->GetConnection();

    // Insert group
    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement("INSERT INTO groups(name) VALUES(?)")
    );

    stmt->setString(1, group->name);
    stmt->executeUpdate();

    // Get generated id
    std::unique_ptr<sql::PreparedStatement> stmtGetId(
        con->prepareStatement("SELECT LAST_INSERT_ID();")
    );
    auto res = std::unique_ptr<sql::ResultSet>(stmtGetId->executeQuery());

    if (res->next())
        return res->getInt(1);

    return -1;
}

void MySQLGroupRepository::update(Group* group)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "UPDATE groups SET name=? WHERE id=?"
        )
    );

    stmt->setString(1, group->name);
    stmt->setInt(2, group->id);

    stmt->executeUpdate();
}

void MySQLGroupRepository::remove(int id)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement("DELETE FROM groups WHERE id=?")
    );

    stmt->setInt(1, id);
    stmt->executeUpdate();
}

bool MySQLGroupRepository::isSubjectInGroup(int subjectId, int groupId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM group_subjects WHERE subject_id = ? AND group_id = ?"
        )
    );

    stmt->setInt(1, subjectId);
    stmt->setInt(2, groupId);
    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    if (res->next())
    {
        return res->getInt("count") > 0;
    }

    return false;
}

void MySQLGroupRepository::assignSubjectToGroup(int groupId, int subjectId)
{
    auto con = db->GetConnection();

    if (isSubjectInGroup(subjectId, groupId))
    {
        throw std::runtime_error("Dalikas jau yra priskirtas prie sios grupies.");
    }

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "INSERT IGNORE INTO group_subjects (group_id, subject_id) VALUES (?, ?)"
        )
    );

    stmt->setInt(1, groupId);
    stmt->setInt(2, subjectId);
    stmt->executeUpdate();


}

std::vector<Subject*> MySQLGroupRepository::getSubjects(int groupId)
{
    std::vector<Subject*> list;
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT s.id, s.name, s.credit_id "
            "FROM subjects s "
            "JOIN group_subject gs ON s.id = gs.subject_id "
            "WHERE gs.group_id = ?"
        )
    );

    stmt->setInt(1, groupId);
    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next()) {
        list.push_back(new Subject(
            res->getInt("id"),
            res->getString("name"),
            res->getInt("credit_id"),
            0
        ));
    }
    return list;
}

bool MySQLGroupRepository::isStudentInGroup(int studentId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM group_students WHERE user_id = ?"
        )
    );

    stmt->setInt(1, studentId);
    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    if (res->next())
    {
        return res->getInt("count") > 0;
    }

    return false;
}

void MySQLGroupRepository::assignStudentToGroup(int studentId, int groupId)
{
    auto con = db->GetConnection();

    if (isStudentInGroup(studentId))
    {
        throw std::runtime_error("Studentas jau yra priskirtas.");
    }

    std::unique_ptr<sql::PreparedStatement> insertStmt(
        con->prepareStatement("INSERT INTO group_students (group_id, user_id) VALUES (?, ?)")
    );
    insertStmt->setInt(1, groupId);
    insertStmt->setInt(2, studentId);

    insertStmt->executeUpdate();
}

int MySQLGroupRepository::getGroupIdByName(const std::string& groupName)
{
    auto con = db->GetConnection();
    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement("SELECT id FROM groups WHERE name = ? LIMIT 1")
    );

    stmt->setString(1, groupName);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
    if (!res->next()) return -1;

    int groupId = res->getInt("id");

    return groupId;

}

void MySQLGroupRepository::removeSubjectFromGroup(int groupId, int subjectId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "DELETE FROM group_subjects WHERE group_id = ? AND subject_id = ?"
        )
    );

    stmt->setInt(1, groupId);
    stmt->setInt(2, subjectId);

    stmt->executeUpdate();
}

void MySQLGroupRepository::removeStudentFromGroup(int userId, int groupId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "DELETE FROM group_students WHERE user_id = ? AND group_id = ?"
        )
    );

    stmt->setInt(1, userId);
    stmt->setInt(2, groupId);

    stmt->executeUpdate();
}

bool MySQLGroupRepository::hasStudents(int groupId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM group_students WHERE group_id = ?"
        )
    );

    stmt->setInt(1, groupId);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
    if (res->next())
        return res->getInt("count") > 0;

    return false;
}

bool MySQLGroupRepository::hasSubjects(int groupId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM group_subjects WHERE group_id = ?"
        )
    );

    stmt->setInt(1, groupId);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
    if (res->next())
        return res->getInt("count") > 0;

    return false;
}

std::vector<User*> MySQLGroupRepository::getStudentsInGroup(int groupId)
{
    std::vector<User*> result;

    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT u.id, u.first_name, u.last_name "
            "FROM group_students gs "
            "JOIN users u ON gs.user_id = u.id "
            "WHERE gs.group_id = ?"
        )
    );

    stmt->setInt(1, groupId);

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        result.push_back(
            new User(
                res->getInt("id"),
                res->getString("first_name"),
                res->getString("last_name"),
                "student"
            )
        );
    }

    return result;
}

std::vector<Subject*> MySQLGroupRepository::getSubjectsForStudent(int studentId)
{
    std::vector<Subject*> subjects;

    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT "
            "s.id AS subjectId, "
            "s.name AS subjectName, "
            "c.number AS creditNumber, "
            "g.id AS groupId, "
            "g.name AS groupName "
            "FROM group_students gs "
            "JOIN groups g ON gs.group_id = g.id "
            "JOIN group_subjects grp ON g.id = grp.group_id "
            "JOIN subjects s ON grp.subject_id = s.id "
            "JOIN credits c ON s.credits_id = c.id "
            "WHERE gs.user_id = ?;"
        )
    );

    stmt->setInt(1, studentId);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    while (res->next())
    {
        Subject* sub = new Subject(
            res->getInt("subjectId"),
            res->getString("subjectName"),
            res->getInt("creditNumber"),
            res->getInt("groupId"),
            res->getString("groupName")
        );

        subjects.push_back(sub);
    }

    return subjects;
}


