#ifndef CHECKING_ACCOUNT_TYPE_H
#define CHECKING_ACCOUNT_TYPE_H

#include "bankAccountType.h"
#include <string>

class checkingAccountType : public bankAccountType
{
public:
    checkingAccountType(const std::string& name, int accountNumber, double accountBalance, int foreignKey = -1);

    int getForeignKey() const;

private:
    int foreignKey_;
};

#endif // CHECKING_ACCOUNT_TYPE_H  