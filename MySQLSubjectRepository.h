#pragma once
#include "ISubjectRepository.h"
#include "Database.h"

class MySQLSubjectRepository : public ISubjectRepository {
private:
    Database* db;

public:
    MySQLSubjectRepository(Database* db);

    std::vector<Subject*> getAll() override;
    int add(Subject* entity) override;
    void update(Subject* entity) override;
    void remove(int id) override;
    bool isTeacherInSubject(int teacherId, int subjectId) override;
    void assignTeacherToSubject(int subjectId, int teacherId) override;
    std::vector<User*> getTeachers(int subjectId) override;
    void removeTeacherFromSubject(int subjectId, int teacherId) override;

    bool isAssignedToAnyGroup(int subjectId) override;
    bool isAssignedToAnyTeacher(int subjectId) override;

};