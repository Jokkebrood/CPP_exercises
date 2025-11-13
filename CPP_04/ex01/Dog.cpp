#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain;
	std::cout << "Dog: Standard constructor" << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog: Copy constructor" << std::endl;
	_brain = new Brain(*src._brain);
	_type = src._type;
}

Dog& Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		this->_type = src._type;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog: Destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}
