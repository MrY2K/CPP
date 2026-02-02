#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
    if ( ac == 1 )
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {    
        for (size_t i = 1; av[i]; i++)
        {
            std::string tmp = av[i];
            for (size_t j = 0; j < tmp.length(); j++)
                std::cout << (char)std::toupper(tmp[j]);
        }
        std::cout << std::endl;
    }
    return 0;
}