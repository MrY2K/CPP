#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
    this->_hitPoints = FragTrap::_hitPoints;       // 100
    this->_energyPoints = ScavTrap::_energyPoints; // 50
    this->_attackDamage = FragTrap::_attackDamage; // 30
    
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    std::cout << "DiamondTrap " << _name << " Constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other) 
{
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap Assignment Operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " Destructed" << std::endl;
}

// The Special Function
void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap: " << _name 
              << ", and my ClapTrap name is: " << ClapTrap::_name << std::endl;
}

// Explicit Attack Override (to use ScavTrap's attack)
// Note: Put this in the .cpp only if you didn't inline it in the header.
// If you used 'using ScavTrap::attack' in the header, you DON'T need to implement it here.