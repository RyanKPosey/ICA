#ifndef CHECKING_ACCOUNT_LIST_H
#define CHECKING_ACCOUNT_LIST_H
#include <vector>
#include "checkingAccountType.h"
class checkingAccountList
{
public:
    checkingAccountList();
    ~checkingAccountList();

    void addAccount(checkingAccountType* account);
    void removeAccount(int accountNumber);
    checkingAccountType* getAccount(int accountNumber) const;
    void printAllAccounts() const;
private:
    std::vector<checkingAccountType*> accounts_;
};
#endif // CHECKING_ACCOUNT_LIST_H