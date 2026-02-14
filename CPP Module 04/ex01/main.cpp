#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    
    // --- ARRAY TEST ---
    std::cout << "\n--- ARRAY test---" << std::endl;

    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; i++)
    {
        animals[i] = new Dog();
    }

    for (int i = arraySize / 2; i < arraySize; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n--- DELETING ARRAY ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        delete animals[i];
    }

    std::cout << "\n---------------" << std::endl;


    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "--" << std::endl;
    }

    std::cout << "cxxcxcxcxcxc" << std::endl;

    return 0;
}

