#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    // srand(1337);

    std::cout << "--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid-Level", 50);
    Bureaucrat intern("Intern", 140);

    std::cout << "\n--- Creating Forms ---" << std::endl;
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "\n--- Testing Shrubbery ---" << std::endl;
    intern.executeForm(shrub); // Fails: Not signed yet
    intern.signForm(shrub);    // Success: 140 <= 145
    intern.executeForm(shrub); // Fails: Grade 140 too low to execute (needs 137)
    mid.executeForm(shrub);    // Success: Grade 50 <= 137 (Creates home_shrubbery file)

    std::cout << "\n--- Testing Robotomy ---" << std::endl;
    mid.signForm(robot);       // Success: 50 <= 72
    mid.executeForm(robot);    // Fails: Grade 50 too low to execute (needs 45)
    boss.executeForm(robot);   // Success: 1 <= 45 (50% chance of success)
    boss.executeForm(robot);   // Do it again to see the 50/50 chance in action!

    std::cout << "\n--- Testing Presidential ---" << std::endl;
    intern.signForm(pardon);   // Fails: Grade 140 too low to sign (needs 25)
    boss.signForm(pardon);     // Success: 1 <= 25
    boss.executeForm(pardon);  // Success: 1 <= 5

    return 0;
}