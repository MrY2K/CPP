#include "ScalarConverter.hpp"

static bool isFloat(const std::string &str);
static bool isDouble(const std::string &str);

static void printChar(char c);
static void printInt(int i);
static void printFloat(float f);
static void printDouble(double d);

void ScalarConverter::convert(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf"
        || str == "nanf" || str == "+inff" || str == "-inff")
    {
        // handle special cases:
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";

        if (str == "nan" || str == "nanf")
            std::cout << "float: nanf\ndouble: nan\n";


        else if (str == "+inf" || str == "+inff")
            std::cout << "float: +inff\ndouble: +inf\n";


        else
            std::cout << "float: -inff\ndouble: -inf\n";

        return;
    }

    else if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
    {
        // char
        char c = str[0];
        
        // The Casts
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        printChar(c);
        printInt(i);
        printFloat(f);
        printDouble(d);
        return;
    }

    else if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f' && isFloat(str))
    {
        // float
        float f = static_cast<float>(std::strtod(str.c_str(), NULL));
        
        // The Casts
        double d = static_cast<double>(f);

        if (f < 0 || f > 127)
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(f));

        if (static_cast<long>(f) < INT_MIN || static_cast<long>(f) > INT_MAX)
            std::cout << "int: impossible\n";
        else
            printInt(static_cast<int>(f));

        printFloat(f);
        printDouble(d);
        return;
    }

    else if (str.find('.') != std::string::npos && isDouble(str))
    {
        // double
        double d = std::strtod(str.c_str(), NULL);
        
        // Cast
        float f = static_cast<float>(d);

        if (d < 0 || d > 127)
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(d));

        if (d < INT_MIN || d > INT_MAX)
            std::cout << "int: impossible\n";
        else
            printInt(static_cast<int>(d));

        printFloat(f);
        printDouble(d);
        return;
    }

    else
    {
        // int

        char* endptr = NULL;
        long l = std::strtol(str.c_str(), &endptr, 10);
    
        if (*endptr != '\0')
        {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }


        if ( l > INT_MAX || l < INT_MIN )
        {
            // immposi
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        int i = static_cast<int>(l);
    
        // Cast
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        if (i < 0 || i > 127)
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(i));

        printInt(i);
        printFloat(f);
        printDouble(d);

    }
}

static bool isFloat(const std::string &str)
{
    int dots = 0;
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    for (; i < (int)str.length() - 1; i++)
    {
        if (str[i] == '.')
            dots++;
        else if (!std::isdigit(str[i]))
            return false;
        if (dots > 1)
            return false;
    }

    return (dots == 1 && str[str.length() - 1] == 'f');
}

static bool isDouble(const std::string &str)
{
    int dots = 0;
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < (int)str.length(); i++)
    {
        if (str[i] == '.')
            dots++;
        else if (!std::isdigit(str[i]))
            return false;
        if (dots > 1)
            return false;
    }
    return (dots == 1);
}

// -------------------------

static void printChar(char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void printInt(int i)
{
    std::cout << "int: " << i << std::endl;
}

static void printFloat(float f)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
