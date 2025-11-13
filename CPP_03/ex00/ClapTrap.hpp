#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap &src);
		ClapTrap operator=(ClapTrap& src);
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
