#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << red << "ERROR: bad input" << reset << std::endl;
		std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
		return (1);
	}
	try
	{
		RPN rpn(av[1]);
//		std::cout << rpn << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
