#include "Subject.h"

Subject::Subject(int id, const std::string& name, int creditId, int creditNumber)
    : id(id), name(name), creditId(creditId), creditNumber(creditNumber) {
}

Subject::Subject(int id, const std::string& name, int creditId, int creditNumber, const std::string& groupName)
    : id(id), name(name), creditId(creditId), creditNumber(creditNumber), groupName(groupName) {
}

Subject::Subject(int id, const std::string& name, int creditId, int creditNumber, const std::string& groupName, const std::string& teacherName)
    : id(id), name(name), creditId(creditId), creditNumber(creditNumber), groupName(groupName), teacherName(teacherName) {
}

Subject::Subject(int id, const std::string name, int creditNumber, std::string groupName)
    : id(id), name(name), creditNumber(creditNumber), groupName(groupName) { }
