#ifndef CERTIFICATE_OF_DEPOSIT_TYPE_H
#define CERTIFICATE_OF_DEPOSIT_TYPE_H

#include "bankAccountType.h"
#include <string>

class certificateOfDepositType : public bankAccountType
{
public:
    certificateOfDepositType(const std::string& name,int accountNumber,double balance,double interestRate,int maturityMonths);

    void createMonthlyStatement() override;
    void withdraw(double amount) override;
    void print() const override;

private:
    double interestRate_;
    int monthsLeft_;
};

#endif
