#include "certificateOfDepositType.h"
#include <iostream>

certificateOfDepositType::certificateOfDepositType(const std::string& name,int accountNumber,double balance,double interestRate,int maturityMonths)
    : bankAccountType(name, accountNumber, balance),
      interestRate_(interestRate),
      monthsLeft_(maturityMonths)
{
}

void certificateOfDepositType::createMonthlyStatement()
{
    balance_ += balance_ * interestRate_;
    if (monthsLeft_ > 0) monthsLeft_--;
}

bool certificateOfDepositType::withdraw(double amount)
{
    if (amount <= 0.0) return false;

    if (monthsLeft_ == 0)
    {
        return bankAccountType::withdraw(amount);
    }
    return false;
}

void certificateOfDepositType::print() const
{
    std::cout << "[certificateOfDepositType]\n";
    bankAccountType::print();
    std::cout << "Interest rate: " << (interestRate_ * 100) << "%\n";
    std::cout << "Months left: " << monthsLeft_ << "\n";
}
