#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
    _index = 0;
    _count = 0;
}

static std::string helper_getInput(std::string prompt)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            exit(0); // Closes safely if user presses Ctrl+D
        if (!input.empty())
            return (input);
        std::cout << "Field cannot be empty!" << std::endl;
    }
}

void    PhoneBook::add()
{
    Contact new_contact;

    std::cout << "\n--- ADDING NEW CONTACT ---" << std::endl;
    // We use the helper to ensure no field is left blank
    new_contact.setFirstName(helper_getInput("First Name: "));
    new_contact.setLastName(helper_getInput("Last Name: "));
    new_contact.setNickname(helper_getInput("Nickname: "));
    new_contact.setPhoneNumber(helper_getInput("Phone Number: "));
    new_contact.setDarkestSecret(helper_getInput("Darkest Secret: "));

    _contacts[_index] = new_contact;

    _index++;

    if (_index >= 8)
        _index = 0;
    
    if (_count < 8)
        _count++;

    std::cout << "--- CONTACT SAVED ---\n" << std::endl;
}

static std::string    helper_trancateString(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    PhoneBook::search()
{
    if (_count == 0)
    {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }

    // 1. Print Table Header
    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "|__________|__________|__________|__________|" << std::endl;

    // 2. Print All Rows
    for (int i = 0; i < _count; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << helper_trancateString(_contacts[i].c()) << "|";
        std::cout << std::setw(10) << helper_trancateString(_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << helper_trancateString(_contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << " ------------------------------------------- " << std::endl;

    // 3. Select Index
    std::string indexStr = helper_getInput("Enter index: ");

    // 4. Validate (Must be single digit & within range)
    if (indexStr.length() == 1 && indexStr[0] >= '0' && indexStr[0] <= '7')
    {
        int i = indexStr[0] - '0';
        if (i < _count)
        {
            _contacts[i].displayFullInfo();
            return;
        }
    }
    std::cout << "Invalid index!" << std::endl;
}

void    PhoneBook::help()
{
    std::cout << "Enter a command: ADD, SEARCH, or EXIT" << std::endl;
}