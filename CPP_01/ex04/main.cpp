#include "ReplacementFile.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Bad input" << std::endl;
		return 0;
	}
	ReplacementFile replacement((std::string)av[1]);
	replacement.makeNewFile();
	replacement.copyIntoNewFile((std::string)av[2], (std::string)av[3]); 
	return 0;
}
