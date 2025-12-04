#pragma once
#include "ICreditRepository.h"
#include "Database.h"

class MySQLCreditRepository : public ICreditRepository {
private:
    Database* db;

public:
    MySQLCreditRepository(Database* db);

    std::vector<Credit*> getAll() override;
};