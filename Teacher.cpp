#include "Teacher.h"

Teacher::Teacher() {}
Teacher::Teacher(int id, const std::string& firstName, const std::string& lastName)
	: User(id, firstName, lastName, "teacher") {
}