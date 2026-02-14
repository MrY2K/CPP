#include "Dog.hpp"


Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Assignment Operator called" << std::endl;

    if (this != &other)
        this->type = other.type;

    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "haw! HAW! " << std::endl; 
}