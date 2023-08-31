#pragma once

#include <iostream>

class Fixed
{
private:
    int value;
    static const int Bits = 8;

public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;

    // Overloaded insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};
