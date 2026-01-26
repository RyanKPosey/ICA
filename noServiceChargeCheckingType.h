#ifndef NO_SERVICE_CHARGE_CHECKING_TYPE_H
#define NO_SERVICE_CHARGE_CHECKING_TYPE_H

#include <string>
#include "bankAccountType.h"

class noServiceChargeCheckingType : public bankAccountType
{
public:
    noServiceChargeCheckingType(const std::string& name, int accountNumber, double accountBalance);
};

#endif