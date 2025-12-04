#pragma once
#include "IGradeRepository.h";
#include "Database.h"

class MySQLGradeRepository : public IGradeRepository
{
private:
	Database* db;

public:
	MySQLGradeRepository(Database* db);
	std::vector<Grade*> getGradesForStudent(int studentId, int subjectId) override;
	void addGrade(int studentId, int subjectId, int number, const std::string& typeName) override;
	std::vector<Grade*> getAllGradeTypes() override;
	int findExistingGrade(int studentId, int subjectId, int gradeTypeId) override;
	int getGradeIdByName(const std::string& gradeType) override;
};
	