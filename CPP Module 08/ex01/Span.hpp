#pragma once

#include <vector>
#include <exception>
#include <iostream>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _contanoor;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Errooor : lbus 3amer";
            }
    };

    class SpanNotEnoughNumbersException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Errooor : there are only 0 or 1 elements inside :/";
            }
    };

template <typename Iterator>
void addNumber(Iterator begin, Iterator end)
{
    if ((((((((((((((((      (_contanoor.size() + std::distance(begin, end) > _maxSize)      ))))))))))))))))
        throw SpanFullException();

    _contanoor.insert(_contanoor.end(), begin, end);
}
};
