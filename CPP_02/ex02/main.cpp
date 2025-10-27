#include "Fixed.hpp"

int main( void )
{
	/*
	   Fixed a;
	   Fixed const b( 10 );
	   Fixed const c( 42.42f );
	   Fixed const d( b );
	   a = Fixed( 1234.4321f );
	   std::cout << "a is " << a << std::endl;
	   std::cout << "b is " << b << std::endl;
	   std::cout << "c is " << c << std::endl;
	   std::cout << "d is " << d << std::endl;
	   std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	   std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	   std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	   std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	 */

	std::cout << std::endl;
	Fixed a(5.5f);
	Fixed b(2.0f);
	Fixed c(a);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << std::endl;
	std::cout <<
		"THIS PART TEST THE ARITHMIC OPERATORS"
		<<std::endl;
	std::cout << std::endl;
	Fixed sum = a + b;
	Fixed diff = a - b;
	Fixed prod = a * b;
	Fixed quot = a / b;

	std::cout << "a + b = " << sum << std::endl;
	std::cout << "a - b = " << diff << std::endl;
	std::cout << "a * b = " << prod << std::endl;
	std::cout << "a / b = " << quot << std::endl;
	std::cout << std::endl;
	std::cout << "COMPARISON OPERATORS TEST\n" << std::endl;

	std::cout << std::boolalpha; // display true/false instead of 1/0

	std::cout << "a < b  : " << (a < b) << std::endl;
	std::cout << "a > b  : " << (a > b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << std::endl;
	std::cout << "Comparing a and c (where c = a):" << std::endl;
	std::cout << std::endl;
	std::cout << "a == c : " << (a == c) << std::endl;
	std::cout << "a != c : " << (a != c) << std::endl;
	std::cout << "a <= c : " << (a <= c) << std::endl;
	std::cout << "a >= c : " << (a >= c) << std::endl;
	std::cout << std::endl;
	return 0;
}
