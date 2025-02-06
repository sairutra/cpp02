#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	return (val / (1 << fractional));
}

float Fixed::toFloat(void) const
{
	return ((float)val / (1 << fractional));
}

int Fixed::getRawBits(void) const
{
	return (val);
}

void Fixed::setRawBits(const int raw)
{
	val = raw;
}

int Fixed::getFractional(void) const
{
	return (fractional);
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	val = fixed.getRawBits();
	return (*this);
}

std::ostream& operator<< (std::ostream &out, const Fixed& fixed)
{
	out << float(fixed.getRawBits()) / float((1 << (8)));
	return (out);
}

Fixed::Fixed(const int value)
{
	std::cout << "Constant int constructor called" << std::endl;
	val = (value << (fractional));
}

Fixed::Fixed(const float value)
{
	std::cout << "Constant float constructor called" << std::endl;
	val = (int)(value * float(1 << (fractional)));
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	val = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	val = fixed.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
