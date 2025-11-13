#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Hello, I'm a fragTrap constructor and have been called"<< std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Hello, I'm a fragTrap constructor and have been called"<< std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &src)
{
	std::cout << "Hello, I'm a fragTrap constructor and have been called"<< std::endl;
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
}

FragTrap& FragTrap::operator=(FragTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "I AM A FRAGTRAP DESTRUCTOR, DESTROYER OF DATA!!!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << _name << " attacked " << target << ", causing "
			<< _attackDamage << " points of damage! I'm FragTrap" << std::endl;
		--_energyPoints;
	}
	else
		std::cout << _name << " is a FragTrap and too tired to attack..." << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << _name << " has taken " << amount << " damage, he is a FragTrap and has "
	<< _hitPoints << " hit points left" << std::endl;
	if (_hitPoints == 0)
		std::cout << _name << " IS DEAD!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << _name << " is a FragTrap and has been revived!" << std::endl;
	else
		std::cout << _name << " is a FragTrap and has been healed!" << std::endl;
	_hitPoints += amount;
	std::cout << "He is a FragTrap and now has "
		<< _hitPoints << " hit points!" << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << _name << " gives some guy a high five" << std::endl;
}
