#include "MySQLGradeRepository.h"
#include <memory>

MySQLGradeRepository::MySQLGradeRepository(Database* db)
    : db(db) {}

std::vector<Grade*> MySQLGradeRepository::getGradesForStudent(int studentId, int subjectId)
{
    std::vector<Grade*> result;

    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT "
            "g.id AS gradeId, "
            "g.number AS gradeNumber, "
            "gt.name AS type "
            "FROM grade_students gs "
            "JOIN grades g ON g.id = gs.grade_id "
            "JOIN grade_type gt ON gt.id = g.grade_type_id "
            "WHERE gs.student_id = ? AND gs.subject_id = ?;"
        )
    );

    stmt->setInt(1, studentId);
    stmt->setInt(2, subjectId);

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        result.push_back(
            new Grade(
                res->getInt("gradeId"),
                res->getInt("gradeNumber"),
                res->getString("type")
            )
        );
    }

    return result;
}

std::vector<Grade*> MySQLGradeRepository::getAllGradeTypes()
{
    std::vector<Grade*> result;

    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement("SELECT id, name FROM grade_type ORDER BY id")
    );

    auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery());

    while (res->next())
    {
        result.push_back(new Grade(
            res->getInt("id"),
            res->getString("name")
        ));
    }

    return result;
}


void MySQLGradeRepository::addGrade(int studentId, int subjectId, int number, const std::string& typeName)
{
    auto con = db->GetConnection();

    // 1. Get grade type ID
    std::unique_ptr<sql::PreparedStatement> gt(
        con->prepareStatement("SELECT id FROM grade_type WHERE name = ? LIMIT 1")
    );
    gt->setString(1, typeName);
    std::unique_ptr<sql::ResultSet> gtRes(gt->executeQuery());

    if (!gtRes->next())
        throw std::runtime_error("Netinkamas pažymio tipas: " + typeName);

    int typeId = gtRes->getInt("id");

    // 2. Check if student already has this type grade
    int existingGradeId = findExistingGrade(studentId, subjectId, typeId);

    if (existingGradeId != -1)
    {
        // UPDATE grade
        std::unique_ptr<sql::PreparedStatement> update(
            con->prepareStatement("UPDATE grades SET number = ? WHERE id = ?")
        );
        update->setInt(1, number);
        update->setInt(2, existingGradeId);
        update->executeUpdate();

        return;
    }

    // 3. INSERT INTO grades
    std::unique_ptr<sql::PreparedStatement> insertGrade(
        con->prepareStatement(
            "INSERT INTO grades (number, grade_type_id) VALUES (?, ?)"
        )
    );
    insertGrade->setInt(1, number);
    insertGrade->setInt(2, typeId);
    insertGrade->executeUpdate();

    // 4. Get new grade ID
    std::unique_ptr<sql::PreparedStatement> getId(
        con->prepareStatement("SELECT LAST_INSERT_ID()")
    );
    std::unique_ptr<sql::ResultSet> idRes(getId->executeQuery());

    int gradeId = 0;
    if (idRes->next())
        gradeId = idRes->getInt(1);

    // 5. INSERT into grade_students
    std::unique_ptr<sql::PreparedStatement> insertGS(
        con->prepareStatement(
            "INSERT INTO grade_students (subject_id, student_id, grade_id) VALUES (?, ?, ?)"
        )
    );
    insertGS->setInt(1, subjectId);
    insertGS->setInt(2, studentId);
    insertGS->setInt(3, gradeId);
    insertGS->executeUpdate();
}



int MySQLGradeRepository::findExistingGrade(int studentId, int subjectId, int gradeTypeId)
{
    auto con = db->GetConnection();

    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement(
            "SELECT g.id "
            "FROM grade_students gs "
            "JOIN grades g ON gs.grade_id = g.id "
            "WHERE gs.student_id = ? AND gs.subject_id = ? AND g.grade_type_id = ?"
        )
    );

    stmt->setInt(1, studentId);
    stmt->setInt(2, subjectId);
    stmt->setInt(3, gradeTypeId);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
    if (res->next())
        return res->getInt("id");

    return -1;
}

int MySQLGradeRepository::getGradeIdByName(const std::string& gradeType)
{
    auto con = db->GetConnection();
    std::unique_ptr<sql::PreparedStatement> stmt(
        con->prepareStatement("SELECT id FROM grade_type WHERE name = ? LIMIT 1")
    );

    stmt->setString(1, gradeType);

    std::unique_ptr<sql::ResultSet> res(stmt->executeQuery());
    if (!res->next()) return -1;

    return res->getInt("id");

}


