#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook   book;
    std::string input;

    std::cout << "Welcome to the Awesome PhoneBook!" << std::endl;
    std::cout << "Enter one of the following commands: ADD, SEARCH, EXIT" << std::endl;

    while (true)
    {
        // 1. Show prompt
        std::cout << "> ";
        
        // 2. Get input (Handle Ctrl+D to exit cleanly)
        if (!std::getline(std::cin, input))
            break;

        // 3. Check commands
        if (input == "ADD")
        {
            book.add();
        }
        else if (input == "SEARCH")
        {
            book.search();
        }
        else if (input == "EXIT")
        {
            break;
        }
        // (Optional: handle invalid input, or just loop silently)
    }
    return (0);
}