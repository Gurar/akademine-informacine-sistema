#pragma once
#include <vector>
#include "Grade.h"
class IGradeRepository
{
public:
    virtual std::vector<Grade*> getGradesForStudent(int studentId, int subjectId) = 0;
    virtual void addGrade(int studentId, int subjectId, int number, const std::string& typeName) = 0;
    virtual std::vector<Grade*> getAllGradeTypes() = 0;
    virtual int findExistingGrade(int studentId, int subjectId, int gradeTypeId) = 0;
    virtual int getGradeIdByName(const std::string& gradeType) = 0;
    
};
