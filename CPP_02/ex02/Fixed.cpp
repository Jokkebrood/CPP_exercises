#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

/******************************************************************************/
/*                                CONSTRUCTORS                                */
/******************************************************************************/


Fixed::Fixed() : _fixedPointVal(0) {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int integer)
{
	this->_fixedPointVal = integer << this->_fractBits;
}

Fixed::Fixed(const float floater)
{
	this->_fixedPointVal = roundf(floater * (1 << this->_fractBits));
}

/******************************************************************************/
/*                               DESTRUCTOR                                   */
/******************************************************************************/

Fixed::~Fixed() {}

/******************************************************************************/
/*                              OPERATORS                                     */
/******************************************************************************/

Fixed& Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_fixedPointVal = src.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

/******************************* Comparison operators *************************/

bool	Fixed::operator<(Fixed const &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>(Fixed const &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<=(Fixed const &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>=(Fixed const &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator==(Fixed const &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed const &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

/****************************** Arithmetic Operators **************************/

float Fixed::operator+(Fixed &fixed)
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed &fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed &fixed)
{
	return (this->toFloat() / fixed.toFloat());
}

/******************************************************************************/
/*                              GETTERS/SETTERS                               */
/******************************************************************************/

int Fixed::getRawBits(void) const
{
	return this->_fixedPointVal;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

/******************************************************************************/
/*                                TRANSFORMERS                                */
/******************************************************************************/

int Fixed::toInt(void) const
{
	return this->_fixedPointVal >> this->_fractBits;
}

float Fixed::toFloat(void) const
{
	return (float)(this->_fixedPointVal) / (float)(1 << this->_fractBits);
}
