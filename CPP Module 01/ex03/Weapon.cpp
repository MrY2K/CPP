#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

std::string const &Weapon::getType()
{
    return this->type;
}

void               Weapon::setType(std::string new_type)
{
    type = new_type;
}