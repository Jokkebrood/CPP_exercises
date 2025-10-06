#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void setName(std::string name);
		const std::string& getName();
		void attack();
		void setWeapon(Weapon &weapon);
};
