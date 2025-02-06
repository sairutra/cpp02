#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << b - a << std::endl;
	std::cout << a / b << std::endl;
	std::cout << b / a << std::endl;
	std::cout << "a: " << a << " b " << b<< std::endl;
	std::cout << (a == a) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	a = b;	
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	return (0);
}
