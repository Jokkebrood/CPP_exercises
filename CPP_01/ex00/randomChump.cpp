#include "Zombie.hpp"

void Zombie::randomChump(std::string randomName)
{
	Zombie zombie(randomName);
	zombie.announce();
}
