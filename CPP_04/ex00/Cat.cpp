#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::Cat(const Cat &src)
{
	_type = src._type;
}

Cat& Cat::operator=(const Cat &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}
