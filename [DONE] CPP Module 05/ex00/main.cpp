#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n------\n";
    try 
    {
        Bureaucrat LBob("LBob", 42);
        std::cout << LBob << std::endl; // Testing the << overload
        
        LBob.incrementGrade();
        std::cout << "After increment: " << LBob << std::endl;
        
        LBob.decrementGrade();
        std::cout << "After decrement: " << LBob << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n------\n";
    try 
    {
        Bureaucrat hmida("hmida", 0);
        std::cout << hmida << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n------\n";
    try 
    {
        Bureaucrat chocho("chocho", 151); // Should throw immediately
        std::cout << chocho << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n------\n";
    try 
    {
        Bureaucrat dave("Dave", 1);
        std::cout << dave << std::endl;
        
        dave.incrementGrade(); // Grade 1 -> 0, should throw!
        
        std::cout << "fgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfg" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n------\n";
    try 
    {
        Bureaucrat riri("riri", 150);
        std::cout << riri << std::endl;
        
        riri.decrementGrade(); // grade 150 -> 151
        
        std::cout << "fgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfgfg" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


































// * exceptions:
// #include <stdexcept> // standard exceptions

// // A function that might fail
// void checkAge(int age) 
// {
//     if (age < 18)
//     {
//         // 1. THROW: We create an error object and throw it out of the function.
//         // The code stops here. The next line is never reached.
//         throw std::invalid_argument("Error: You must be 18 or older!"); 
//     }
//     std::cout << "Access granted." << std::endl;
// }

// int main() 
// {
//     // 2. TRY: We put risky code inside this block.
//     try 
//     {
//         checkAge(15); 
//         std::cout << "This line will not print because the error stopped it early." << std::endl;
//     }
//     // 3. CATCH: If a throw happens above, it teleports down to here.
//     catch (const std::exception& e) 
//     {
//         // e.what() prints the message we attached to the throw
//         std::cout << "We caught a problem! " << e.what() << std::endl; 
//     }

//     std::cout << "The program continues running normally..." << std::endl;
//     return 0;
// }