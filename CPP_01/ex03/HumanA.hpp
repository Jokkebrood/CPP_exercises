#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void setName(std::string name);
		const std::string& getName();
		void attack();
};
