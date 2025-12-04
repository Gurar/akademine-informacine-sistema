#pragma once
#include "ITeacherRepository.h"
#include "Database.h"

class MySQLTeacherRepository : public ITeacherRepository
{
private:
	Database* db;
public:
	MySQLTeacherRepository(Database* db);
	std::vector<Subject*> getTeacherSubjects(int teacherId) override;
	std::vector<User*> getStudentsForSubject(int subjectId) override;
};