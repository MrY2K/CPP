#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructor
AMateria::AMateria(std::string const & type) : _type(type)
{

}

// Copy Constructor
AMateria::AMateria(const AMateria& other) : _type(other._type)
{

}


AMateria& AMateria::operator=(const AMateria& other)
{
    (void)other;
    return *this;
}

// Destructor
AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}