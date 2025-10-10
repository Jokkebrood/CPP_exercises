#include "Harl.cpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Bad input" << std::endl;
		return 0;
	}
	Harl harl;
	harl.complain((std::string)av[1]);
}
