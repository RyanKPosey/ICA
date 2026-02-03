#include "passwordPrompt.h"
#include <iostream>

std::string promptForPassword()
{
    std::string password;
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    return password;
}