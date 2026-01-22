#ifndef HIGH_INTEREST_CHECKING_TYPE_H
#define HIGH_INTEREST_CHECKING_TYPE_H

#include "bankAccountType.h"
#include <string>

class highInterestCheckingType : public bankAccountType
{
public:
    highInterestCheckingType(const std::string& name, int accountNumber, double balance);

    void createMonthlyStatement() override;
    void print() const override;

private:
    double monthlyInterestRate_ = 0.02;
};

#endif
