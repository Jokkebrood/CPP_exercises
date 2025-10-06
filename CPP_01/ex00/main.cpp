#include "Zombie.hpp"

int main()
{
	std::string randomName = "random zombie";
	std::string newName = "new zombie";
	Zombie *zombie;
	
	randomChump(randomName);
	zombie = newZombie(newName);
	zombie->announce();
	delete zombie;
	return 0;
}
