#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "Please add a file to parse" << std::endl;
	else if (ac > 2)
		std::cout << "Can only parse one file at a time" << std::endl;
	else
	{
		try
		{
			FindData find(av[1]);
		}
		catch (std::invalid_argument &e)
		{
			std::cout << e.what()<< std::endl;
		}
	}
	return 0;
}
