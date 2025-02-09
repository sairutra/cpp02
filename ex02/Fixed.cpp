#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	return (val / (1 << fractional));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(val) / (1 << fractional);
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

const Fixed& Fixed::min (const Fixed& f1, const Fixed& f2) 
{
	return (f1 < f2 ? f1 : f2);
}
Fixed& Fixed::min (Fixed& f1, Fixed& f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed& Fixed::max (const Fixed& f1, const Fixed& f2) 
{
	return (f1 > f2 ? f1 : f2);
}

Fixed& Fixed::max (Fixed& f1, Fixed& f2)
{
	return (f1 > f2 ? f1 : f2);
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this == &fixed)
		return (*this);
	val = fixed.getRawBits();
	return (*this);
}

bool operator==(const Fixed& f1, const Fixed& f2)
{
	return (f1.getRawBits() == f2.getRawBits());
}

bool operator!=(const Fixed& f1, const Fixed& f2)
{
	return !(f1 == f2);
}

bool operator< (const Fixed& f1, const Fixed& f2)
{
	return (f1.getRawBits() < f2.getRawBits());
}

bool operator> (const Fixed& f1, const Fixed& f2)
{
	return !(f1 < f2);
}

bool operator>= (const Fixed& f1, const Fixed& f2)
{
	return !(f1 > f2);
}

bool operator<= (const Fixed& f1, const Fixed& f2)
{
	return !(f1 < f2);
}

std::ostream& operator<< (std::ostream &out, const Fixed& fixed)
{
	out << float(fixed.getRawBits()) / float((1 << (8)));
	return (out);
}

Fixed operator+ (const Fixed& f1, const Fixed& f2)
{
	return (Fixed(f1.toFloat() + f2.toFloat()));
}

Fixed operator- (const Fixed& f1, const Fixed& f2)
{
	return (Fixed(f1.toFloat() - f2.toFloat()));
}

Fixed operator/ (const Fixed& f1, const Fixed& f2)
{
	return (Fixed(f1.toFloat() / f2.toFloat()));
}

Fixed operator* (const Fixed& f1, const Fixed& f2)
{
	return (Fixed(f1.toFloat() * f2.toFloat()));
}

Fixed& Fixed::operator++ ()
{
	int raw;

	raw = getRawBits();
	setRawBits(++raw);
	return (*this);
}

Fixed& Fixed::operator-- ()
{
	int raw;

	raw = getRawBits();
	setRawBits(--raw);
	return (*this);
}

Fixed Fixed::operator++ (int)
{
	Fixed temp{*this};
	int raw;

	raw = temp.getRawBits();
	setRawBits(++raw);
	return (temp);
}

Fixed Fixed::operator-- (int)
{
	Fixed temp{*this};
	int raw;

	raw = temp.getRawBits();
	setRawBits(--raw);
	return (temp);
}

Fixed::Fixed(const int value)
{
	val = (value << (fractional));
}

Fixed::Fixed(const float value)
{
	val = static_cast<int>(roundf(value * (1 << fractional)));
}

Fixed::Fixed()
{
	val = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	val = fixed.getRawBits();
}

Fixed::~Fixed()
{
}
