#include "checkingAccountType.h"
#include <iostream>

checkingAccountType::checkingAccountType(const std::string& name, int accountNumber, double accountBalance)
    : bankAccountType(name, accountNumber, accountBalance)
{
}
