#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Hello, I'm a constructor and have been called"<< std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "I AM A DESTRUCTOR, DESTROYER OF DATA!!!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << _name << " attacked " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		--_energyPoints;
	}
	else
		std::cout << _name << " is too tired to attack..." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << _name << " has taken " << amount << " damage, he has "
	<< _hitPoints << " hit points left" << std::endl;
	if (_hitPoints == 0)
		std::cout << _name << " IS DEAD!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << _name << " has been revived!" << std::endl;
	else
		std::cout << _name << " has been healed!" << std::endl;
	_hitPoints += amount;
	std::cout << "He now has " << _hitPoints << " hit points!" << std::endl;
}
