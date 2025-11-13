#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap &src);
		ClapTrap operator=(ClapTrap& src);
		~ClapTrap();

		ClapTrap(std::string name);

		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};
