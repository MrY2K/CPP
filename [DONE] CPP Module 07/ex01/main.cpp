#include <iostream>
#include <string>
#include "iter.hpp"

// 1. A normal, non-template function
void addOne(int& n)
{
    n += 1;
}

// 2. A generic template function
template <typename T>
void printElement(T& elem)
{
    std::cout << elem << " ";
}

int main() {
    // --- Test 1: Integers & Normal Function ---
    int intArray[] = {1, 2, 3, 4, 5};
    
    std::cout << "Original array modified (+1): ";
    ::iter(intArray, 5, addOne);
    ::iter(intArray, 5, printElement<int>);
    std::cout << "\n\n";

    // --- Test 2: Strings & Template Function ---
    std::string strArray[] = {"haha", "gogo", "C++", "hiih."};
    
    std::cout << "String array: ";
    ::iter(strArray, 4, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}