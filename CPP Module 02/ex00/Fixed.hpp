#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{

    private:
        int               _value;
        static const int  _fractionalBits = 8;


    public:
        Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment
        ~Fixed();
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

};


#endif
