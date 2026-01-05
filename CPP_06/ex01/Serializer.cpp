#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
	std::cout << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(Serializer &src)
{
	std::cout << "Serializer copy constructor" << std::endl;
	*this = src;
}

// Destructor
Serializer::~Serializer()
{
	std::cout << "Serializer destructor" << std::endl;
}

// Overload operator
Serializer &Serializer::operator=(Serializer &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}

// Functions

uintptr_t Serializer::serialize(Data* ptr)
{
	return (uintptr_t)ptr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *data = (Data *)raw;
	return data;
}
