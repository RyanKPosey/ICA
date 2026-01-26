#ifndef CHECKING_ACCOUNT_TYPE_H
#define CHECKING_ACCOUNT_TYPE_H

#include "bankAccountType.h"
#include <string>

class checkingAccountType : public bankAccountType
{
public:
    checkingAccountType(const std::string& name, int accountNumber, double accountBalance);
};

#endif // CHECKING_ACCOUNT_TYPE_H  