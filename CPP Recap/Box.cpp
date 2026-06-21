#include "Box.hpp"

Box::Box(int width, int height) : _width(width), _height(height) {}

Box::Box(const Box &other) : _width(other._width), _height(other._height) {}

Box &Box::operator=(const Box &other)
{
    if (this != &other)      // always check self-assignment
    {
        _width = other._width;
        _height = other._height;
    }
    return (*this);
}

Box::~Box()
{
    std::cout << "Box destroyed\n";
}

int Box::getArea() const
{
    return (_width * _height);
}

double Circle::getArea() const
{
    return (3.14159 * _radius * _radius);
}

double Rectangle::getArea() const
{
    return (this-> _width * this-> _height);
}


