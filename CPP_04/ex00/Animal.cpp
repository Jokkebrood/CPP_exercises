#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {}

Animal::Animal(const Animal &src) : _type(src._type) {}

Animal::Animal(const std::string &type) : _type(type) {}

Animal::~Animal() {}

Animal& Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

const std::string &Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal sound" << std::endl;
}
