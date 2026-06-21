#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _GradToSign(150),  _GradToExecute(150)
{

}

Form::Form(std::string name, const int GradToSign,  const int GradToExecute) : _name(name), _signed(false), _GradToSign(GradToSign),  _GradToExecute(GradToExecute)
{
    if (GradToSign < 1 || GradToExecute < 1)
        throw Form::GradeTooHighException();
        
    if (GradToSign > 150 || GradToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _GradToSign(other._GradToSign), _GradToExecute(other._GradToExecute)
{
//copy constructooor
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_signed = other._signed; 
    }
    return *this;
}

Form::~Form()
{
    //distractooor
}

/// GETTERS :
const std::string   Form::getName() const
{
    return this->_name;
}


bool                Form::getSigned() const
{
    return this->_signed;
}

int                 Form::getGradToSign() const
{
    return this->_GradToSign;
}

int                 Form::getGradToExecute() const
{
    return this->_GradToExecute;
}

// --- Exceptions ---
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// ---


void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if ( bureaucrat.getGrade() > this->_GradToSign )
        throw Form::GradeTooLowException();

    this->_signed = true;
}




// ---

std::ostream& operator<<(std::ostream& out, const Form& f) 
{
    out << "Form " << f.getName() << ", signed: ";
    
    if (f.getSigned())
        out << "yes";
    else
        out << "no";
        
    out << ", sign grade: " << f.getGradToSign()
        << ", exec grade: " << f.getGradToExecute();
        
    return out;
}