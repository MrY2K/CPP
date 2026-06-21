#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- Test 1: Bureaucrat signs successfully ---" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        Form tax("Tax Form 1040", 50, 50);
        std::cout << tax << std::endl;
        ceo.signForm(tax);
        std::cout << tax << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Bureaucrat fails to sign (Grade too low) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Form nda("Super Secret NDA", 10, 10);
        std::cout << nda << std::endl;
        intern.signForm(nda); // This will catch an exception internally!
        std::cout << nda << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Creating a Form with invalid grades ---" << std::endl;
    try {
        Form impossible("Impossible Form", 0, 100); // Throws immediately!
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}