#pragma once

#include "iostream"
#include "string"

class Animal
{
	public:
		const std::string& getType() const;
		virtual void makeSound() const = 0;
		virtual ~Animal();
	protected:
		Animal();
		Animal(const Animal &src);
		Animal& operator=(const Animal &src);
		Animal(const std::string &type);

		std::string _type;
};
