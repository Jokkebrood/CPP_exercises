#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();
		void makeSound() const;
	private:
		Brain* _brain;
};
