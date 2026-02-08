#include "loginInterface.h"

#include <iostream>
#include <string>
#include <functional>
#include <sstream>

LoginInterface::LoginInterface()
    : lastUserId_{-1}, lastEmail_{""}
{
}

bool LoginInterface::login(const std::string& email, const std::string& password, const AccountsDatabase& db)
{
    const AccountRecord* record = db.findByEmail(email);
    if (record == nullptr)
        return false;

    const std::string hashedPassword = hashPassword(password);
    if (hashedPassword != record->passwordHash)
        return false;

    lastUserId_ = record->userId;
    lastEmail_ = email;
    return true;
}

bool LoginInterface::promptAndLogin(const AccountsDatabase& db)
{
    std::string email = promptForEmail();
    std::string password = promptForPassword();

    return login(email, password, db);
}

int LoginInterface::getLastUserId() const
{
    return lastUserId_;
}

std::string LoginInterface::getLastEmail() const
{
    return lastEmail_;
}

std::string LoginInterface::promptForEmail() const
{
    std::string email;
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    return email;
}

std::string LoginInterface::promptForPassword() const
{
    std::string password;
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    return password;
}

std::string LoginInterface::hashPassword(const std::string& password) const
{
    const std::size_t hashed = std::hash<std::string>{}(password);
    std::ostringstream out;
    out << std::hex << hashed;
    return out.str();
}

void LoginInterface::createAccount(AccountsDatabase& db)
{
    std::string email = promptForEmail();
    std::string password = promptForPassword();

    AccountStatus status = db.addAccount(email, password);
    std::cout << db.statusMessage(status) << std::endl;
}

int LoginInterface::getUserMenuChoice() const
{
    int choice;
    std::cout << "\n=== Login Menu ===" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter choice (1-3): ";
    std::cin >> choice;
    std::cin.ignore(); 
    return choice;
}

void LoginInterface::displayMenu(AccountsDatabase& db)
{
    int choice;
    bool running = true;

    while (running)
    {
        choice = getUserMenuChoice();

        switch (choice)
        {
        case 1:
            std::cout << "\n--- Login ---" << std::endl;
            if (promptAndLogin(db))
            {
                std::cout << "Login successful!" << std::endl;
                std::cout << "User ID: " << getLastUserId() << std::endl;
                std::cout << "Email: " << getLastEmail() << std::endl;
            }
            else
            {
                std::cout << "Login failed. Invalid email or password." << std::endl;
            }
            break;

        case 2:
            std::cout << "\n--- Create Account ---" << std::endl;
            createAccount(db);
            break;

        case 3:
            std::cout << "Exiting..." << std::endl;
            running = false;
            break;

        default:
            std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
        }
    }
}
