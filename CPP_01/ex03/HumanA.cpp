#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
	:_name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::setName(std::string name)
{
	_name = name;
}

const std::string& HumanA::getName()
{
	return _name;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
