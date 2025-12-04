#include "Student.h"

Student::Student() {}

Student::Student(int id, const std::string& firstName, const std::string& lastName)
	: User(id, firstName, lastName, "student") {
}