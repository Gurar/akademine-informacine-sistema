#include "Admin.h"

Admin::Admin() {};

Admin::Admin(int id, const std::string& firstName, const std::string& lastName)
	: User(id, firstName, lastName, "admin") {
}