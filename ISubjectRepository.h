#pragma once
#include "IRepository.h"
#include "Subject.h"
#include "User.h"

class ISubjectRepository : public IRepository<Subject>
{
public:
	virtual void assignTeacherToSubject(int subjectId, int teacherId) = 0;
	virtual std::vector<User*> getTeachers(int subjectId) = 0;
	virtual bool isTeacherInSubject(int teacherId, int subjectId) = 0;
	virtual void removeTeacherFromSubject(int subjectId, int teacherId) = 0;
	virtual bool isAssignedToAnyGroup(int subjectId) = 0;
	virtual bool isAssignedToAnyTeacher(int subjectId) = 0;
};