#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap &srs);
		ScavTrap& operator=(ScavTrap &src);
		~ScavTrap();

		ScavTrap(std::string name);
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		void guardGate();
};
