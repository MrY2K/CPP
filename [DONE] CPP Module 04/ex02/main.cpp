#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //! THIS WILL NOW CAUSE A COMPILER ERROR:
    // Animal* test = new Animal(); 

    //* THIS STILL WORKS PERFECTLY:
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}