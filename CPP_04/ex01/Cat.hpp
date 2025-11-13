#pragma once

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat& operator=(const Cat &src);
		~Cat();
		void makeSound() const;
	private:
		Brain* _brain;
};
