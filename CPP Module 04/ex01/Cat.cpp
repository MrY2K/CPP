#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Assignment Operator called" << std::endl;

    if (this != &other)
    {
        this->type = other.type;

        delete this->_brain;
        this->_brain = new Brain(*other._brain);

    }

    return *this;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miw! Miw! Miw!" << std::endl;
}
