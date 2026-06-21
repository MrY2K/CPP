#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() 
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    std::cout << "est 1: Valid Form" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    // if (form)
    // {
        boss.signForm(*form);
        boss.executeForm(*form);
    // }

    std::cout << "\n-Invalid Form" << std::endl;
    
    form = someRandomIntern.makeForm("coffee request", "Boss");


    return 0;
}