#ifndef HIGH_INTEREST_SAVINGS_TYPE_H
#define HIGH_INTEREST_SAVINGS_TYPE_H

#include <string>
#include "bankAccountType.h"

class highInterestSavingsType : public bankAccountType
{
public:
    highInterestSavingsType(const std::string& name, int accountNumber, double accountBalance);           
};

#endif
