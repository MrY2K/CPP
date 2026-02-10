#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

    private:
        int               _value;
        static const int  _fractionalBits = 8;


    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment
        ~Fixed();
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    float   toFloat(void) const;
    int     toInt(void) const;

    // 1. Comparison Operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // 2. Arithmetic Operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // 3. Increment/Decrement Operators
    Fixed& operator++();       // Pre-increment (++i)
    Fixed operator++(int);     // Post-increment (i++)
    Fixed& operator--();       // Pre-decrement (--i)
    Fixed operator--(int);     // Post-decrement (i--)

    // 4. Static Min Max Functions
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
