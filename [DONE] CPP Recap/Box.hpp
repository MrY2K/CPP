#pragma once

#include <iostream>

class Box
{
    private:
        int _width;
        int _height;

    public:
        Box(int width, int height);
        Box(const Box &other);
        Box &operator=(const Box &other);
        ~Box();

        int getArea() const;
};

class Shape
{
    virtual ~Shape();             // virtual destructor — important
    virtual double getArea() const = 0; // pure virtual
};

class Rectangle : public Shape
{
    private:
        int _width;
        int _height;

    public:
        Rectangle(int _width, int _height);
        Rectangle(const Rectangle& other);
        Rectangle& operator=(const Rectangle& other);
        ~Rectangle();    

        double getArea() const;
};

class Circle : public Shape
{
    private:
        int _radius;

    public:
        Circle(int _radius);
        Circle(const Circle& other);
        Circle& operator=(const Circle& other) ;
        ~Circle();    

        double getArea() const;
};

class Score
{
    private:
        int     _points;

    public:
        Score(int _points);
        Score(const Score &other);
        Score&operator=(const Score &other);
        ~Score();

    Score operator+(const Score &other) const;    
    friend std::ostream &operator<<(std::ostream &out, const Score &s);
};
