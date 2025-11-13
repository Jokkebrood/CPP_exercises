#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Hello, I'm a scavTrap constructor and have been called"<< std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Hello, I'm a scavTrap constructor and have been called"<< std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &src)
{
	std::cout << "Hello, I'm a scavTrap constructor and have been called"<< std::endl;
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
}

ScavTrap& ScavTrap::operator=(ScavTrap& src)
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

ScavTrap::~ScavTrap()
{
	std::cout << "I AM A SCAVTRAP DESTRUCTOR, DESTROYER OF DATA!!!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << _name << " attacked " << target << ", causing "
			<< _attackDamage << " points of damage! I'm ScavTrap" << std::endl;
		--_energyPoints;
	}
	else
		std::cout << _name << " is a ScavTrap and too tired to attack..." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << _name << " has taken " << amount << " damage, he is a ScavTrap and has "
	<< _hitPoints << " hit points left" << std::endl;
	if (_hitPoints == 0)
		std::cout << _name << " IS DEAD!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << _name << " is a ScavTrap and has been revived!" << std::endl;
	else
		std::cout << _name << " is a ScavTrap and has been healed!" << std::endl;
	_hitPoints += amount;
	std::cout << "He is a ScavTrap and now has "
		<< _hitPoints << " hit points!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is guarding a gate" << std::endl;
}
