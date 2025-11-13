#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string newName)
{
	Zombie* zombie = new Zombie(newName);
	return zombie;
}
