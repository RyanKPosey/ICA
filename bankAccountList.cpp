#include "bankAccountList.h"
bankAccountList::bankAccountList()
{
}
bankAccountList::~bankAccountList()
{
    for (auto account : accounts_)
    {
        delete account;
    }
}
void bankAccountList::addAccount(bankAccountType* account)
{
    accounts_.push_back(account);
}
void bankAccountList::removeAccount(int accountNumber)
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
bankAccountType* bankAccountList::getAccount(int accountNumber) const
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
void bankAccountList::printAllAccounts() const
{
    for (const auto& account : accounts_)
    {
        account->print();
        std::cout << "-----------------------\n";
    }
}
