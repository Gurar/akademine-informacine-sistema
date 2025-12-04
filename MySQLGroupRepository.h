#pragma once
#include "IGroupRepository.h"
#include "Database.h"

class MySQLGroupRepository : public IGroupRepository
{
private:
    Database* db;

public:
    MySQLGroupRepository(Database* db);

    std::vector<Group*> getAll() override;
    int add(Group* entity) override;
    void update(Group* entity) override;
    void remove(int id) override;
    void assignSubjectToGroup(int groupId, int subjectId) override;
    std::vector<Subject*> getSubjects(int groupId) override;
    void assignStudentToGroup(int studentId, int groupId)  override;
    bool isStudentInGroup(int studentId) override;
    bool isSubjectInGroup(int subjectId, int groupId) override;
    int getGroupIdByName(const std::string& groupName) override;
    void removeSubjectFromGroup(int groupId, int subjectId) override;
    void removeStudentFromGroup(int userId, int groupId) override;
    bool hasStudents(int groupId) override;
    bool hasSubjects(int groupId) override;
    std::vector<User*> getStudentsInGroup(int groupId);
    std::vector<Subject*> getSubjectsForStudent(int studentId) override;

};