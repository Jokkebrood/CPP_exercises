#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_fixedPointVal = integer << this->_fractBits;
}

Fixed::Fixed(const float floater)
{
	std::cout << "Floating point constructor called" << std::endl;
	this->_fixedPointVal = roundf(floater * (1 << this->_fractBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointVal = src.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointVal;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointVal = raw;
}

int Fixed::toInt(void) const
{
	return this->_fixedPointVal >> this->_fractBits;
}

float Fixed::toFloat(void) const
{
	return (float)(this->_fixedPointVal) / (float)(1 << this->_fractBits);
}
