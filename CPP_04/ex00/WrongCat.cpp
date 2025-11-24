#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Wrong Cat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "Wrong Cat copy constructor" << std::endl;
	_type = src._type;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor" << std::endl;
}
