#include "ScalerConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Expected input: one number" << std::endl;
		return 0;
	}
	try
	{
		ScalerConverter converter(av[1]);
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
