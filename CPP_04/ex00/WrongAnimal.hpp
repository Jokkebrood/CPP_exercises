#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal& operator=(const WrongAnimal &src);
		virtual ~WrongAnimal();

		const std::string& getType() const;
		void makeSound() const;
	protected:
		WrongAnimal(const std::string &type);
		std::string _type;
};
