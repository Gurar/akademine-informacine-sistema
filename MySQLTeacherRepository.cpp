#include "MySQLTeacherRepository.h"

MySQLTeacherRepository::MySQLTeacherRepository(Database* db)
    : db(db) {
}

std::vector<Subject*> MySQLTeacherRepository::getTeacherSubjects(int teacherId)
{
    std::vector<Subject*> result;
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT "
            "s.id AS subjectId, "
            "s.name AS subjectName, "
            "c.number AS creditNumber, "
            "g.name AS groupName "
            "FROM subject_teacher st "
            "JOIN subjects s ON st.subject_id = s.id "
            "JOIN credits c ON s.credits_id = c.id "
            "LEFT JOIN group_subjects gs ON s.id = gs.subject_id "
            "LEFT JOIN groups g ON gs.group_id = g.id "
            "WHERE st.teacher_id = ?;"
        )
    );

    stmt->setInt(1, teacherId);
    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        Subject* item = new Subject(
            res->getInt("subjectId"),
            res->getString("subjectName"),
            res->getInt("creditNumber"),
            res->isNull("groupName") ? "" : res->getString("groupName")
        );

        result.push_back(item);
    }

    return result;
}

std::vector<User*> MySQLTeacherRepository::getStudentsForSubject(int subjectId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT u.id, u.first_name, u.last_name "
            "FROM group_subjects gs "
            "JOIN group_students gstu ON gs.group_id = gstu.group_id "
            "JOIN users u ON gstu.student_id = u.id "
            "WHERE gs.subject_id = ?"
        )
    );

    stmt->setInt(1, subjectId);
    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    std::vector<User*> students;

    while (res->next()) {
        students.push_back(new User(
            res->getInt("id"),
            res->getString("first_name"),
            res->getString("last_name"),
            "student"
        ));
    }

    return students;
}