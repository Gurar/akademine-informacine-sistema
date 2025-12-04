#include "MySQLSubjectRepository.h"

MySQLSubjectRepository::MySQLSubjectRepository(Database* db)
    : db(db) {
}

std::vector<Subject*> MySQLSubjectRepository::getAll()
{
    std::vector<Subject*> list;

    auto con = db->GetConnection();
    std::unique_ptr<sql::Statement> stmt(con->createStatement());


    auto res = std::unique_ptr<sql::ResultSet>(
        stmt->executeQuery(
            "SELECT s.id, s.name, s.credits_id, c.number AS creditNumber, "
            "g.name AS groupName, "
            "CONCAT(u.first_name, ' ', u.last_name) AS teacherName "
            "FROM subjects s "
            "JOIN credits c ON s.credits_id = c.id "
            "LEFT JOIN group_subjects gs ON s.id = gs.subject_id "
            "LEFT JOIN groups g ON gs.group_id = g.id "
            "LEFT JOIN subject_teacher st ON s.id = st.subject_id "
            "LEFT JOIN users u ON st.teacher_id = u.id;"
        )
    );

    while (res->next()) {
        list.push_back(new Subject(
            res->getInt("id"),
            res->getString("name"),
            res->getInt("credits_id"),
            res->getInt("creditNumber"),
            res->getString("groupName"),
            res->getString("teacherName")
        ));
    }

    return list;
}

int MySQLSubjectRepository::add(Subject* subject)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "INSERT INTO subjects(name, credits_id) VALUES (?, ?)"
        )
    );

    stmt->setString(1, subject->name);
    stmt->setInt(2, subject->creditId);
    stmt->executeUpdate();

    std::unique_ptr<sql::PreparedStatement> stmt2(
        con->prepareStatement("SELECT LAST_INSERT_ID();")
    );

    auto res = std::unique_ptr<sql::ResultSet>(stmt2->executeQuery());

    if (res->next())
        return res->getInt(1);

    return -1;
}

void MySQLSubjectRepository::update(Subject* subject)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "UPDATE subjects SET name=?, credits_id=? WHERE id=?"
        )
    );

    stmt->setString(1, subject->name);
    stmt->setInt(2, subject->creditId);
    stmt->setInt(3, subject->id);

    stmt->executeUpdate();
}

void MySQLSubjectRepository::remove(int id)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "DELETE FROM subjects WHERE id=?"
        )
    );

    stmt->setInt(1, id);
    stmt->executeUpdate();
}

bool MySQLSubjectRepository::isTeacherInSubject(int teacherId, int subjectId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM subject_teacher WHERE subject_id = ? AND teacher_id = ?"
        )
    );

    stmt->setInt(1, subjectId);
    stmt->setInt(2, teacherId);
    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());

    if (res->next())
    {
        return res->getInt("count") > 0;
    }

    return false;
}

void MySQLSubjectRepository::assignTeacherToSubject(int subjectId, int teacherId)
{
    auto con = db->GetConnection();

    if (isTeacherInSubject(teacherId, subjectId))
    {
        throw std::runtime_error("Destitojas jau priskirtas prie daliko.");
    }

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "INSERT IGNORE INTO subject_teacher (subject_id, teacher_id) VALUES (?, ?)"
        )
    );

    stmt->setInt(1, subjectId);
    stmt->setInt(2, teacherId);
    stmt->executeUpdate();
}

std::vector<User*> MySQLSubjectRepository::getTeachers(int subjectId)
{
    std::vector<User*> list;
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT u.id, u.first_name, u.last_name "
            "FROM users u "
            "JOIN subject_teacher st ON u.id = st.teacher_id "
            "WHERE st.subject_id = ?"
        )
    );

    stmt->setInt(1, subjectId);
    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        list.push_back(new User(
            res->getInt("id"),
            res->getString("first_name"),
            res->getString("last_name"),
            "teacher"
        ));
    }
    return list;
}

void MySQLSubjectRepository::removeTeacherFromSubject(int subjectId, int teacherId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "DELETE FROM subject_teacher WHERE subject_id = ? AND teacher_id = ?"
        )
    );

    stmt->setInt(1, subjectId);
    stmt->setInt(2, teacherId);

    stmt->executeUpdate();
}

bool MySQLSubjectRepository::isAssignedToAnyGroup(int subjectId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM group_subjects WHERE subject_id = ?"
        )
    );

    stmt->setInt(1, subjectId);

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    if (res->next())
        return res->getInt("count") > 0;

    return false;
}

bool MySQLSubjectRepository::isAssignedToAnyTeacher(int subjectId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT COUNT(*) AS count FROM subject_teacher WHERE subject_id = ?"
        )
    );

    stmt->setInt(1, subjectId);

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    if (res->next())
        return res->getInt("count") > 0;

    return false;
}




