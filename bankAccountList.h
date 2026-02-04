#ifndef BANK_ACCOUNT_LIST_H
#define BANK_ACCOUNT_LIST_H
#include <vector>
#include "bankAccountType.h"
class bankAccountList
{
public:
    bankAccountList();
    ~bankAccountList();

    void addAccount(bankAccountType* account);
    void removeAccount(int accountNumber);
    bankAccountType* getAccount(int accountNumber) const;
    void printAllAccounts() const;
private:
    std::vector<bankAccountType*> accounts_;
};
#endif // BANK_ACCOUNT_LIST_H