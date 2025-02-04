#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	return (0);
}

int Fixed::setRawBits(void) const
{
	return (0);
}

Fixed::Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this == &fixed)
		return (*this);
	number_value = fixed.number_value;
	return (*this);
}

Fixed::Fixed(const Fixed& fixed)
{

}

Fixed::~Fixed()
{
}
