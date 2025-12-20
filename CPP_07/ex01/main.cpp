#include "iter.hpp"

void printString(std::string string)
{
	std::cout << string << std::endl;
}

void addition(int a)
{
	std::cout << a << " + " << a << " = " << a + a << std::endl;
}

int main()
{
	std::cout << "FUNCTION THAT PRINTS A STRING" << std::endl;
	std::string string[3] = {"poop haha", "pipi haha", "time to get serious"};
	::iter(string, 3, printString);
	std::cout << std::endl;

	std::cout <<
		"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << std::endl;

	std::cout << "FUNCTION THAT PRINTS WHAT A NUMBER ADDED TO ITSELF IS" <<std::endl;
	int list[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	::iter(list, 10, addition);
	return 0;
}
