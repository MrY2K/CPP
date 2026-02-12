#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- FRAGTRAP TEST ---" << std::endl;
    FragTrap frag("FRAGGY");

    frag.attack("Target");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFiveGuys();
    
    std::cout << "\n--- DESTRUCTION ---" << std::endl;
    return 0;
}