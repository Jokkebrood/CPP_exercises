#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		PmergeMe pmerge(ac, av);
		std::cout << pmerge << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << red << "ERROR: " << e.what() << reset << std::endl;
	}
}
