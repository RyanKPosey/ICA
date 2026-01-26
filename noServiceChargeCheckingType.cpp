#include <iostream>
#include "noServiceChargeCheckingType.h"

noServiceChargeCheckingType::noServiceChargeCheckingType(const std::string& name, int accountNumber, double accountBalance)
    : bankAccountType(name, accountNumber, accountBalance)
{
    std::cout << "noServiceChargeCheckingType constructor\n";
}