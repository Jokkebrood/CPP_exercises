#include "Zombie.hpp"

int main()
{
	std::string newName = "Zombie nr. 1";
	Zombie *zombie;
	
	zombie = zombieHorde(80, newName);
	zombie[0].announce();
	delete[] zombie;
	return 0;
}
