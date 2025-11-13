#pragma once

#include "iostream"
#include "string"

class Animal
{
	public:
		virtual ~Animal() = 0;

		const std::string& getType() const;
		virtual void makeSound() const;
	protected:
		Animal();
		Animal(const Animal &src);
		Animal& operator=(const Animal &src);
		Animal(const std::string &type);
		std::string _type;
};
