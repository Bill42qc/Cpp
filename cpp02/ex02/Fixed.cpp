#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
	: value(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
//	std::cout << "Int constructor called" << std::endl;
	value = intValue << Bits;
}

Fixed::Fixed(const float floatValue)
{
//	std::cout << "Float constructor called" << std::endl;
	value = roundf(floatValue * (1 << Bits));
}

Fixed::Fixed(const Fixed &other)
	: value(other.value)
{
//	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(value) / (1 << Bits));
}

int Fixed::toInt() const
{
	return (value >> Bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &other) 
{
	if (this != &other)
	{
//		std::cout << "Copy assignment operator called" << std::endl;
		value = other.value;
	}
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (value > other.value ? true : false);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (value < other.value ? true : false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (value <= other.value ? true : false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (value >= other.value ? true : false);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (value == other.value ? true : false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (value != other.value ? true : false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if(other.value == 0)
		return(0);
	return (this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++()
{
	this->value++;
	return (*this);
}
Fixed Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	this->value++;
	return(copy);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	this->value--;
	return(copy);
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}