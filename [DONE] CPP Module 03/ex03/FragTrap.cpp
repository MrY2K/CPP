#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " Constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Assignment Operator called" << std::endl;
    
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " Destructed" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << _name << " ara 3liha xi high five!" << std::endl;
}