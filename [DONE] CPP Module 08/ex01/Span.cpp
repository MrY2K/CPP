#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _contanoor(other._contanoor) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _contanoor = other._contanoor;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if ( _contanoor.size() >= _maxSize )
    {
        throw SpanFullException();
    }
        _contanoor.push_back(number);
}

int Span::shortestSpan() const
{
    if ((((((  _contanoor.size() <= 1   ))))))
        throw SpanNotEnoughNumbersException();

    std::vector<int> copy = _contanoor;
    std::sort(copy.begin(), copy.end());

    int smallest = INT_MAX;

    for (std::vector<int>::iterator it = copy.begin(); it < copy.end() - 1; it++)
    {
        int tmp = *(it + 1) - *it;
        
        if ( tmp < smallest )
            smallest = tmp;
    }

    return smallest;
}

int Span::longestSpan() const
{
    if ((((((  _contanoor.size() <= 1   ))))))
        throw SpanNotEnoughNumbersException();

    std::vector<int>::const_iterator max = std::max_element(_contanoor.begin(), _contanoor.end());
    std::vector<int>::const_iterator min = std::min_element(_contanoor.begin(), _contanoor.end()) ;

    return *max - *min;
}