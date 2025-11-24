#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal string constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

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
