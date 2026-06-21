// #include "Box.hpp"
#include <iostream>

// class Score
// {
//     private:
//         int     _points;

//     public:
//         Score(int _points);
//         Score(const Score &other);
//         Score&operator=(const Score &other);
//         ~Score();

//     Score operator+(const Score &other) const;    
//     friend std::ostream &operator<<(std::ostream &out, const Score &s);
// };

// Score::Score(int _points) : _points(_points) {}

// Score::~Score() {}


// Score Score::operator+(const Score &other) const
// {
//     return Score(other._points + this->_points);
// }

// std::ostream &operator<<(std::ostream &out, const Score &s)
// {
//     return (out << s._points);
// }

int     main(void)
{
    int x = 65;
    char c = static_cast<char>(x);   // 'A'
    float f = static_cast<float>(x); // 65.0f
}