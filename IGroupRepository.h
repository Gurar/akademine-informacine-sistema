#pragma once
#include "IRepository.h"
#include "Group.h"
#include "Subject.h"
#include "User.h"
class IGroupRepository : public IRepository<Group>
{
public:

	virtual std::vector<Subject*> getSubjects(int groupId) = 0;

	virtual bool isStudentInGroup(int studentId) = 0;
	virtual int  getGroupIdByName(const std::string& groupName) = 0;
	virtual void assignStudentToGroup(int studentId, int groupId) = 0;

	virtual void assignSubjectToGroup(int groupId, int subjectId) = 0;

	virtual bool isSubjectInGroup(int subjectId, int groupId) = 0;
	virtual void removeSubjectFromGroup(int groupId, int subjectId) = 0;
	virtual void removeStudentFromGroup(int userId, int groupId) = 0;

	virtual bool hasStudents(int groupId) = 0;
	virtual bool hasSubjects(int groupId) = 0;

	virtual std::vector<User*> getStudentsInGroup(int groupId) = 0;
	virtual std::vector<Subject*> getSubjectsForStudent(int studentId) = 0;
};