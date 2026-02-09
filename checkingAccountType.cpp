#include "checkingAccountType.h"

checkingAccountType::checkingAccountType(const std::string& name, int accountNumber, double accountBalance, int foreignKey)
    : bankAccountType(name, accountNumber, accountBalance), foreignKey_{foreignKey}
{
}

int checkingAccountType::getForeignKey() const
{
    return foreignKey_;
}
