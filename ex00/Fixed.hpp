#include <iostream>

class Fixed
{
private:
	int	number_value;
	static const int fractional{8};
public:
	Fixed();
	Fixed(const Fixed&);
	Fixed& operator= (const Fixed&);
	~Fixed();
	int getRawBits(void) const;
	int setRawBits(void) const;
};


