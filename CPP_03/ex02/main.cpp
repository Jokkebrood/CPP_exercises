#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>

unsigned int stoui(const std::string &message)
{
	std::string input;

	while (true)
	{
		std::cout << message << std::endl;
		if (!std::getline(std::cin, input))
			return 0;
		bool valid = true;
		for (size_t i = 0; i < input.size(); ++i)
		{
			if (!std::isdigit(input[i]))
			{
				valid = false;
				break;
			}
		}
		if (valid && !input.empty())
			return std::atoi(input.c_str());
		std::cout << "Bad input" << std::endl;
	}
}

void choseFragTrap()
{
	std::string input;
	FragTrap fragTrap("Mr. Boingo");

	std::cout << std::endl;
	std::cout << "WHAT WOULD YOU LIKE TO DO?" << std::endl;
	std::cout << "1) attack" << std::endl;
	std::cout << "2) heal" << std::endl;
	std::cout << "3) be attacked" << std::endl;
	std::cout << "4) high five a guy" << std::endl;
	std::cout << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "1")
		{
			std::cout << "Who would you like to attack?" << std::endl;
			getline(std::cin, input);
			fragTrap.attack(input);
		}
		if (input == "2")
		{
			fragTrap.beRepaired(stoui("How much would you like to heal?"));
		}
		if (input == "3")
		{
			fragTrap.takeDamage(stoui("How much damage would you like to take?"));
		}
		if (input == "4")
		{
			fragTrap.highFiveGuys();
		}
	}
}

void choseScavTrap()
{
	std::string input;
	ScavTrap scavTrap("Mr. Boingo");

	std::cout << std::endl;
	std::cout << "WHAT WOULD YOU LIKE TO DO?" << std::endl;
	std::cout << "1) attack" << std::endl;
	std::cout << "2) heal" << std::endl;
	std::cout << "3) be attacked" << std::endl;
	std::cout << "4) gbe a guard" << std::endl;
	std::cout << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "1")
		{
			std::cout << "Who would you like to attack?" << std::endl;
			getline(std::cin, input);
			scavTrap.attack(input);
		}
		if (input == "2")
		{
			scavTrap.beRepaired(stoui("How much would you like to heal?"));
		}
		if (input == "3")
		{
			scavTrap.takeDamage(stoui("How much damage would you like to take?"));
		}
		if (input == "4")
		{
			scavTrap.guardGate();
		}
	}
}

void choseClapTrap()
{
	std::string input;
	ClapTrap clapTrap("Mr. Doink");

	std::cout << std::endl;
	std::cout << "WHAT WOULD YOU LIKE TO DO?" << std::endl;
	std::cout << "1) attack" << std::endl;
	std::cout << "2) heal" << std::endl;
	std::cout << "3) be attacked" << std::endl;
	std::cout << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "1")
		{
			std::cout << "Who would you like to attack?" << std::endl;
			getline(std::cin, input);
			clapTrap.attack(input);
		}
		if (input == "2")
		{
			clapTrap.beRepaired(stoui("How much would you like to heal?"));
		}
		if (input == "3")
		{
			clapTrap.takeDamage(stoui("How much damage would you like to take?"));
		}
	}
}


int main()
{
	std::string input;

	std::cout << "Choose between claptrap and scavtrap" << std::endl
		<< "1) claptrap\n2) scavtrap\n3) fragTrap" << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "1")
			choseClapTrap();
		else if (input == "2")
			choseScavTrap();
		else if (input == "3")
			choseFragTrap();
		else
			std::cout << "Bad input" << std::endl;
	}
}
