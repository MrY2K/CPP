#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _GradToSign(150),  _GradToExecute(150)
{

}

AForm::AForm(std::string name, const int GradToSign,  const int GradToExecute) : _name(name), _signed(false), _GradToSign(GradToSign),  _GradToExecute(GradToExecute)
{
    if (GradToSign < 1 || GradToExecute < 1)
        throw AForm::GradeTooHighException();
        
    if (GradToSign > 150 || GradToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _GradToSign(other._GradToSign), _GradToExecute(other._GradToExecute)
{
//copy constructooor
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_signed = other._signed; 
    }
    return *this;
}

AForm::~AForm()
{
    //distractooor
}

/// GETTERS :
const std::string   AForm::getName() const
{
    return this->_name;
}


bool                AForm::getSigned() const
{
    return this->_signed;
}

int                 AForm::getGradToSign() const
{
    return this->_GradToSign;
}

int                 AForm::getGradToExecute() const
{
    return this->_GradToExecute;
}

// --- Exceptions ---
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// ---


void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if ( bureaucrat.getGrade() > this->_GradToSign )
        throw AForm::GradeTooLowException();

    this->_signed = true;
}




// ---

std::ostream& operator<<(std::ostream& out, const AForm& f) 
{
    out << "AForm " << f.getName() << ", signed: ";
    
    if (f.getSigned())
        out << "yes";
    else
        out << "no";
        
    out << ", sign grade: " << f.getGradToSign()
        << ", exec grade: " << f.getGradToExecute();
        
    return out;
}