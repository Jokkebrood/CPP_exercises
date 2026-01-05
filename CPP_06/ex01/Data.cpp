#include "Data.hpp"

// Constructors
Data::Data()
{
	std::cout << "Data default constructori" << std::endl;
}

Data::Data(Data &src)
{
	std::cout << "Data Copy constructor" << std::endl;
	*this = src;
}

Data::Data(std::string name, int number, std::string address)
	: _name(name), _number(number), _address(address)
{
	std::cout << "Data input constructor" << std::endl;
}

// Destructor
Data::~Data()
{
	std::cout << "Data destructor" << std::endl;
}

// Operator overload
Data& Data::operator=(Data& src)
{
	if (this != &src)
		*this = src;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Data const &src)
{
	os << "Name: " << src.getName() << std::endl
	<< "Number: " << src.getNumber() << std::endl
	<< "Address: " << src.getAddress();
	return os;
}

// Getters
std::string Data::getName() const { return _name; }

int Data::getNumber() const { return _number; }

std::string Data::getAddress() const { return _address; }
