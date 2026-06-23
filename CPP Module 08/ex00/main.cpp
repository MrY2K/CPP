#include <iostream>
#include <vector>

#include "easyfind.hpp"
#include "easyfind.tpp"

int main(  )
{
    std::vector<int> vivi;
    vivi.push_back(10);
    vivi.push_back(20);
    vivi.push_back(69);
    vivi.push_back(40);
    vivi.push_back(50);

    try
    {
        std::vector<int>::iterator it = easyfind(vivi, 69);
        std::cout << "FOUND IT :" << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "---------------------------------\n";


    try
    {
        std::vector<int>::iterator it = easyfind(vivi, 100);
        std::cout << "FOUND IT :" << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}