#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> _stack;

        bool isOperator(char c) const;
        void performOperation(char op);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void calculate(const std::string& expression);
};