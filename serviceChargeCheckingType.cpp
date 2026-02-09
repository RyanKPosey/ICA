#include "serviceChargeCheckingType.h"
#include <iostream>

serviceChargeCheckingType::serviceChargeCheckingType(const std::string& name, int accountNumber, double balance)
    : bankAccountType(name, accountNumber, balance)
{
}

bool serviceChargeCheckingType::withdraw(double amount)
{
    if (amount <= 0.0) return false;

    if (amount + serviceFee_ <= balance_)
    {
        balance_ -= (amount + serviceFee_);
        return true;
    }
    return false;
}

void serviceChargeCheckingType::print() const
{
    std::cout << "[serviceChargeCheckingType]\n";
    bankAccountType::print();
    std::cout << "Service fee per withdraw: $" << serviceFee_ << "\n";
}
