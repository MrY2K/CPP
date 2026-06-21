#pragma once

#include <string>
#include <iostream>
#include <cstdlib>   // for strtod, strtol
#include <climits>   // for INT_MAX, INT_MIN
#include <cctype>    // for isdigit, isprint
#include <iomanip>   // for setprecision, fixed

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& str);
};

