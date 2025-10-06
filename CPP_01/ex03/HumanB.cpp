#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() 
{
	if (_weapon != NULL)
		delete _weapon;
}

void HumanB::setName(std::string name)
{
	_name = name;
}

const std::string& HumanB::getName()
{
	return _name;
}

void HumanB::attack()
{
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " does not have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	if (_weapon != NULL)
		delete _weapon;
	_weapon = new Weapon(weapon);
}
