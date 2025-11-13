#pragma once

#include "iostream"
#include "string"

class Animal
{
	public:
		Animal();
		Animal(const Animal &src);
		Animal& operator=(const Animal &src);
		virtual ~Animal();

		const std::string& getType() const;
		virtual void makeSound() const;
	protected:
		Animal(const std::string &type);
		std::string _type;
};
