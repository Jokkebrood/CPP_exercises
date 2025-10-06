#pragma once

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void setName(std::string x);
		void announce(void);
};

Zombie* zombieHorde(int n, std::string newName);
