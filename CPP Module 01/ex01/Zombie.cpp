#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "Unamed";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}