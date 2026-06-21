
#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool              _signed;
        const int         _GradToSign;
        const int         _GradToExecute;


    public:
        AForm();
        AForm(std::string name, const int GradToSign,  const int GradToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();


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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw() 
                {
                    return "AForm is not signed!";
                }
        };

        void    beSigned(Bureaucrat& bureaucrat);

        virtual void execute(Bureaucrat const & executor) const = 0;
};

// overload <<
std::ostream& operator<<(std::ostream& out, const AForm& b);

