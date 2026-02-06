#include "Zombie.hpp"

int main()
{
    // Test 1: Heap zombie
    // - Call newZombie() with a name
    Zombie* zomboy = newZombie("Zamboooy");
    zomboy->announce();
    delete zomboy;
    // - DELETE it (critical!)

    // Test 2: Stack zombie  
    // - Call randomChump() with a different name
    randomChump("Random_Ass");
    // - Watch it auto-destruct

    return 0;
}