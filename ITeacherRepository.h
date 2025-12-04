#pragma once
#include <vector>
#include "Subject.h"
#include "User.h"
class ITeacherRepository {
public:
    virtual std::vector<Subject*> getTeacherSubjects(int teacherId) = 0;
    virtual std::vector<User*> getStudentsForSubject(int subjectId) = 0;
};