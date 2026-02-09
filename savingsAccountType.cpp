#include "savingsAccountType.h"

savingsAccountType::savingsAccountType(const std::string& name, int accountNumber, double accountBalance, int foreignKey)
    : bankAccountType(name, accountNumber, accountBalance), foreignKey_{foreignKey}
{
}

int savingsAccountType::getForeignKey() const
{
    return foreignKey_;
}