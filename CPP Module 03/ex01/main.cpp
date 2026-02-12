#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Creating ScavTrap ---" << std::endl;
    ScavTrap guard("popo");

    std::cout << "\n--- Testing Actions ---" << std::endl;
    guard.attack("kaka");
    guard.guardGate();
    
    std::cout << "\n--- Destruction Chain ---" << std::endl;
    return 0;
}