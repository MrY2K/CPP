#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}

//--------------------------------------------------------------------------------

bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int v2 = _stack.top();
    _stack.pop();
    
    int v1 = _stack.top();
    _stack.pop();

    if (op == '+')
         _stack.push(v1 + v2);

    else if (op == '-')
        _stack.push(v1 - v2);

    else if (op == '*')
        _stack.push(v1 * v2);

    else if (op == '/')
    {
        if (v2 == 0) 
            throw std::runtime_error("Error"); // No dividing by zero
        _stack.push(v1 / v2);
    }
}

void RPN::calculate(const std::string& expression)
{
    try
    {
        for (size_t i = 0; i < expression.length(); ++i)
        {
            char c = expression[i];
            
            if (c == ' ')
                continue;
            
            if (isdigit(c))
                _stack.push(c - '0');
            
            else if (isOperator(c))
                performOperation(c);
    
            else
                throw std::runtime_error("Error");
        }

        if (_stack.size() != 1)
            throw std::runtime_error("Error");
            
        std::cout << _stack.top() << std::endl;
        
    }
    
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}