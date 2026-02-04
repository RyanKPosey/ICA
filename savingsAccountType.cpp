#include <iostream>
#include "savingsAccountType.h"

savingsAccountType::savingsAccountType(const std::string& name, int accountNumber, double accountBalance, int foreignKey)
{
    name_ = name;
    accountNumber_ = accountNumber;
    balance_ = accountBalance;
    foreignKey_ = foreignKey;
}