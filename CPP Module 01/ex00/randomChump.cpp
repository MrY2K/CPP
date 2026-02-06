#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie z(name);  // Stack allocation
    z.announce();
    // z dies here at the end  automatically
}