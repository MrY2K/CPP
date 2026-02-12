#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " Constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Assignment Operator called" << std::endl;
    
    if (this != &other)
    {
        ClapTrap::operator=(other); // Call base class assignment
    }

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " Destructed" << std::endl;
}

// Override Attack (Optional but good practice to show it's a different robot)
void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0 || _hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is out of energy/dead." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " violently attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}