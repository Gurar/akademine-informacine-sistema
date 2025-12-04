#include "Grade.h"


Grade::Grade(int id, int number, const std::string& type)
	: id(id), number(number), type(type) { }

Grade::Grade(int id, const std::string& type)
	: id(id), type(type) {
}