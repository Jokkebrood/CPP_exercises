#include "Fixed.hpp"

int main( void )
{
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

	std::cout << "Incremental operators test: i++, ++i, --i and i--" << std::endl;
	std::cout << std::endl;
	std::cout << "b++ : " << b++ << std::endl;
	std::cout << "++b : " << ++b << std::endl;
	std::cout << "b++ : " << b++ << std::endl;

	std::cout << "b-- : " << b-- << std::endl;
	std::cout << "--b : " << --b << std::endl;
	std::cout << "b-- : " << b-- << std::endl;
	std::cout << std::endl;

	std::cout << "Tester for min max" << std::endl;
	std::cout << std::endl;
	Fixed comp;
	const Fixed d(5);
	const Fixed e(10);
	std::cout << "a & b in min: " << comp.min(a, b) << std::endl;
	std::cout << "a & b in max: " << comp.max(a, b) << std::endl;
	std::cout << "const a & b in min: " << comp.min(d, e) << std::endl;
	std::cout << "const a & b in max: " << comp.max(d, e) << std::endl;
	return 0;
}
