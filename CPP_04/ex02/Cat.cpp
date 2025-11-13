#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain;
	std::cout << "Cat: Standard constructor" << std::endl;
}

Cat::Cat(const Cat &src)
{
	_brain = new Brain(*src._brain);
}

Cat& Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		this->_type = src._type;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat: Destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}
