#pragma once
#include "Credit.h"
#include <vector>

class ICreditRepository {
public:
    virtual ~ICreditRepository() {}

    virtual std::vector<Credit*> getAll() = 0;
   
};