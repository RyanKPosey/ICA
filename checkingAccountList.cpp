#include "checkingAccountList.h"
checkingAccountList::checkingAccountList()
{
}
checkingAccountList::~checkingAccountList()
{
    for (auto account : accounts_)
    {
        delete account;
    }
}
void checkingAccountList::addAccount(checkingAccountType* account)
{
    accounts_.push_back(account);
}
void checkingAccountList::removeAccount(int accountNumber)
{
    for (auto it = accounts_.begin(); it != accounts_.end(); ++it)
    {
        if ((*it)->getAccountNumber() == accountNumber)
        {
            delete *it;
            accounts_.erase(it);
            return;
        }
    }
}
checkingAccountType* checkingAccountList::getAccount(int accountNumber) const
{
    for (auto account : accounts_)
    {
        if (account->getAccountNumber() == accountNumber)
        {
            return account;
        }
    }
    return nullptr;
}
void checkingAccountList::printAllAccounts() const
{
    for (const auto& account : accounts_)
    {
        account->print();
        std::cout << "-----------------------\n";
    }
}
