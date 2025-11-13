#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap &srs);
		FragTrap& operator=(FragTrap &src);
		~FragTrap();

		FragTrap(std::string name);
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		void highFiveGuys();
};
