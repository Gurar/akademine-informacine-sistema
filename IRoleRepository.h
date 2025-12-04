#pragma once
#include "Role.h"
#include <vector>

class IRoleRepository
{
public:
    virtual ~IRoleRepository() {}

    virtual std::vector<Role*> getAllRoles() = 0;
};