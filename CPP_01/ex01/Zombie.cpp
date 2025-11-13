#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::Zombie() {}

Zombie::~Zombie() {}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
