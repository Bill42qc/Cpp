#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int intValue)
{
    value = intValue << Bits;
}

Fixed::Fixed(const float floatValue)
{
    value = roundf(floatValue * (1 << Bits));
}

Fixed::Fixed(const Fixed &other) : value(other.value) {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << Bits);
}

int Fixed::toInt() const
{
    return value >> Bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
