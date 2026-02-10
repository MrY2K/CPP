#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other._value; // you an also use the getrawbits() function
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    // Step 1: Check if assigning to itself (if this == &other, do nothing)
    if (this != &other)
    {
        this->_value = other._value;
    }
    
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

/*

-- Copy Assignment Operator 

Fixed a;           // Default constructor
Fixed b(a);        // Copy CONSTRUCTOR - creates new object from existing
Fixed c = a;       // Copy CONSTRUCTOR - also creates new object (looks like assignment but isn't!)

Fixed d;           // Default constructor
d = a;             // Copy ASSIGNMENT - both objects already exist, copying data

*/