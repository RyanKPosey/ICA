#include <iostream>
#include "highInterestSavingsType.h"

highInterestSavingsType::highInterestSavingsType(const std::string& name, int accountNumber, double accountBalance)
    : bankAccountType(name, accountNumber, accountBalance)
{
    std::cout << "highInterestSavingsType constructor\n";
}
