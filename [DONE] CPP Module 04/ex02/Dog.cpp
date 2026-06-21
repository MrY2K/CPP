#include "Dog.hpp"


Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Assignment Operator called" << std::endl;

    if (this != &other)
    {
        this->type = other.type;
    
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }

    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "haw! HAW! " << std::endl; 
}