#include "Zombie.hpp"

int main()
{
	std::string newZombie = "Mr. Newman";
	std::string randomZombie = "Mr. Wacky";
	
	Zombie zombie;
	Zombie *newZomb = zombie.newZombie(newZombie);
	newZomb->announce();
	zombie.randomChump(randomZombie);
	delete newZomb;
	return 0;
}
