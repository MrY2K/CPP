#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// #include <stdlib.h>
// void check_leaks()
// {
//     system("leaks -q a.out");
// }

int main()
{
    // atexit(check_leaks);

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());  
    src->learnMateria(new Cure()); 

    ICharacter* fifi = new Character("fifi"); 
    ICharacter* bob = new Character("bob"); 

    AMateria* tmp;
    tmp = src->createMateria("ice"); 
    fifi->equip(tmp);
    
    tmp = src->createMateria("cure");
    fifi->equip(tmp);


    fifi->use(0, *bob); // Should shoot ice 
    fifi->use(1, *bob); // Should heal 

    delete bob;
    delete fifi;
    delete src;

    return 0;
}