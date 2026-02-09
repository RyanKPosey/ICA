#include "savingsAccountType.h"

savingsAccountType::savingsAccountType(const std::string& name, int accountNumber, double accountBalance, int foreignKey)
    : bankAccountType(name, accountNumber, accountBalance), foreignKey_{foreignKey}
{
}

bool savingsAccountType::withdraw(double amount)
{
    if (amount <= 0.0)
        return false;

    // $5 fee for savings withdrawal
    double totalAmount = amount + 5.00;

    if (totalAmount > getBalance()) {
        return false;
    }

    setBalance(getBalance() - totalAmount);
    return true;
}

int savingsAccountType::getForeignKey() const
{
    return foreignKey_;
}