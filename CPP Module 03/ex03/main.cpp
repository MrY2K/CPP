#include "DiamondTrap.hpp"

int main()
{
    std::cout << "--- CREATING DIAMOND ---" << std::endl;
    DiamondTrap monster("MONSTER");

    std::cout << "\n--- CHECKING STATS & ACTIONS ---" << std::endl;
    monster.whoAmI();
    monster.attack("Victim"); // Should use ScavTrap's attack
    monster.highFiveGuys();   // Should use FragTrap's high five
    monster.guardGate();      // Should use ScavTrap's guard gate
    
    std::cout << "\n--- DESTRUCTION ---" << std::endl;
    return 0;
}