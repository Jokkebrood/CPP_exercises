#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(const Dog &src)
{
	_type = src._type;
}

Dog& Dog::operator=(const Dog &src)
{
	if (this != &src)
		_type = src._type;
	return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}
