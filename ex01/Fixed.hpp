#include <iostream>

const int fixed_max = 16777216;
const int intBitesSize = (sizeof(int) * 8);

class Fixed
{
private:
	int	val;
	static const int fractional{8};
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	Fixed& operator= (const Fixed&);
	~Fixed();
	int getRawBits(void) const;
	int getFractional(void) const;
	void setRawBits(const int) ;
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<< (std::ostream& out, const Fixed&);

