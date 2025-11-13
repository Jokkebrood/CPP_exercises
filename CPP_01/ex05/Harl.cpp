#include "Harl.hpp"

#define NR_LVLS 4

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[NR_LVLS] =
	{
		"debug", 
		"info",
		"warning",
		"error"
	};
	void (Harl::*ptr[NR_LVLS])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < NR_LVLS; i++)
	{
		if (level == levels[i])
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "BAD INPUT" << std::endl;
}
