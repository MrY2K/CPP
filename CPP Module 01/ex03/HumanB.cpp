#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;  // No weapon initially
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;  // Store the address
}

void HumanB::attack()
{
    if (weapon)  // Check if weapon exists
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}