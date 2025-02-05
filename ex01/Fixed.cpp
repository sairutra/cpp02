#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (val);
}

void Fixed::setRawBits(const int raw)
{
	val = raw;
}

int Fixed::toInt(void) const
{
	return (val);
}

float Fixed::toFloat(void) const
{
	return ((float)val);
}

Fixed::Fixed(const int value)
{
	std::cout << "Constant int constructor called" << std::endl;
	for (int i = 0; i < 24; i++)
	{
		int mask = 1 << i;
		int masked_i = value & mask;
		std::cout << (masked_i >> i);
	}
	std::cout << std::endl;
	val = value;
}

Fixed::Fixed(const float value)
{
	std::cout << "Constant float constructor called" << std::endl;
	val = (int)value;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	val = 0;
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
	out << fixed.getRawBits() << std::endl;
	return (out);
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
