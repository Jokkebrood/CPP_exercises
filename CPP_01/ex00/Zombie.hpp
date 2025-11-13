#pragma once

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void announce(void);
		Zombie* newZombie(std::string newName);
		void randomChump(std::string randomName);
};
