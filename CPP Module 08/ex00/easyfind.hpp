#pragma once

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception 
{
    public:
         const char* what() const throw()
        {
            return "Value Not Found In Container :<";
        }
};

