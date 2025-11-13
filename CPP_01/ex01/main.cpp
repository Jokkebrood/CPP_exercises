#include "Zombie.hpp"

int main()
{
	std::string newName = "Zombie nr. 1";
	Zombie *zombie = zombieHorde(80, newName);
	zombie[60].announce();
	delete[] zombie;
	return 0;
}
