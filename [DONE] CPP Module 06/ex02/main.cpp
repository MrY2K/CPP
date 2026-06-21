#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// --- Generate ---
Base* generate(void)
{
    // Randomly return A, B, or C
    int randNum = std::rand() % 3;
    
    if (randNum == 0) {
        std::cout << "Generated: A\n";
        return new A();
    } else if (randNum == 1) {
        std::cout << "Generated: B\n";
        return new B();
    } else {
        std::cout << "Generated: C\n";
        return new C();
    }
}

// --- Identify via Pointer ---
void identify(Base* p)
{
    // If the cast succeeds, it returns the address. If it fails, it returns NULL.
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer identified as: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer identified as: B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer identified as: C\n";
    else
        std::cout << "Pointer identified as: Unknown\n";
}

// --- Identify via Reference ---
void identify(Base& p)
{
    // References can't be NULL. If it fails, it throws an exception.
    // We try to cast to A, if it errors, we silently catch it and try B, etc.
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference identified as: A\n";
        return;
    } catch (std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference identified as: B\n";
        return;
    } catch (std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference identified as: C\n";
        return;
    } catch (std::exception& e) {}
    
    std::cout << "Reference identified as: Unknown\n";
}

int main()
{
    std::srand(std::time(NULL)); // Seed the randomizer

    std::cout << "--- Testing Random Generation ---\n";
    Base* mysteriousObject = generate();

    std::cout << "\n--- Testing Pointer Identify ---\n";
    identify(mysteriousObject);

    std::cout << "\n--- Testing Reference Identify ---\n";
    identify(*mysteriousObject); // Dereference pointer to pass as reference

    delete mysteriousObject; // Prevent leaks!

    return 0;
}