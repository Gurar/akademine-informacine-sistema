#include "MySQLCreditRepository.h"

MySQLCreditRepository::MySQLCreditRepository(Database* db)
    : db(db) {
}

std::vector<Credit*> MySQLCreditRepository::getAll()
{
    std::vector<Credit*> credits;

    auto con = db->GetConnection();
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    auto res = std::unique_ptr<sql::ResultSet>(
        stmt->executeQuery("SELECT id, number FROM credits")
    );

    while (res->next()) {
        credits.push_back(new Credit(
            res->getInt("id"),
            res->getInt("number")
        ));
    }

    return credits;
}