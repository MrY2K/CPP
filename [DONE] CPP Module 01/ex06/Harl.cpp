#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "I love having extra bacon..." << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money..." << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free..." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelIndex = -1;
    
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            levelIndex = i;
    
switch (levelIndex)
{
    case 0:
        std::cout << "[ DEBUG ]\n";
        debug();
        // fall through
    case 1:
        std::cout << "[ INFO ]\n";
        info();
        // fall through
    case 2:
        std::cout << "[ WARNING ]\n";
        warning();
        // fall through
    case 3:
        std::cout << "[ ERROR ]\n";
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
}
}