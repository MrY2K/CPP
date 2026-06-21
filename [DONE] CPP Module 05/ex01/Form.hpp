
#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _GradToSign;
        const int         _GradToExecute;


    public:
        Form();
        Form(std::string name, const int GradToSign,  const int GradToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();


        //getters:
        const std::string   getName() const;
        bool                getSigned() const;
        int                 getGradToSign() const;
        int                 getGradToExecute() const;

        // exeptions:
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        void    beSigned(Bureaucrat& bureaucrat);
};

// overload <<
std::ostream& operator<<(std::ostream& out, const Form& b);

