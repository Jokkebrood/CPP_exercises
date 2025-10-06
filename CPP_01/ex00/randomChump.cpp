#include "Zombie.hpp"

void randomChump(std::string randomName)
{
	Zombie zombie;
	
	zombie.setName(randomName);
	zombie.announce();
}
