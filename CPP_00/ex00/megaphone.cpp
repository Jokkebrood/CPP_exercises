#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; av[i] != NULL; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
				std::cout << (char)toupper(av[i][j]);
		if (av[i + 1] == NULL)
			std::cout << "\n";
		else
			std::cout << " ";
	}
	return(0);
}
