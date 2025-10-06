#pragma once

#include  <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		const std::string &getType();
};
