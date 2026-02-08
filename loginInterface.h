#ifndef LOGIN_INTERFACE_H
#define LOGIN_INTERFACE_H

#include <string>
#include "accountsDatabase.h"

class LoginInterface
{
public:
    LoginInterface();

    // Attempt login with provided email and password
    bool login(const std::string& email, const std::string& password, const AccountsDatabase& db);

    // Prompt user for email and password, then attempt login
    bool promptAndLogin(const AccountsDatabase& db);

    // Create a new account using AccountsDatabase
    void createAccount(AccountsDatabase& db);

    // Display main menu and handle user interaction
    void displayMenu(AccountsDatabase& db);

    // Get the user ID of the last successful login
    int getLastUserId() const;

    // Get the email of the last successful login
    std::string getLastEmail() const;

private:
    std::string promptForEmail() const;
    std::string promptForPassword() const;
    std::string hashPassword(const std::string& password) const;
    int getUserMenuChoice() const;

    int lastUserId_;
    std::string lastEmail_;
};

#endif // LOGIN_INTERFACE_H
