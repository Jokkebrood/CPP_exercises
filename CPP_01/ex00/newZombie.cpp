#include "Zombie.hpp"

Zombie* newZombie(std::string newName)
{
	Zombie* zombie = new Zombie();
	zombie->setName(newName);
	return zombie;
}
