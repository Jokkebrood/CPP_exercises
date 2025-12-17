#include "Serializer.hpp"

// Constructors
Serializer::Serializer() {}
Serializer::Serializer(Serializer &src)
{
	*this = src;
}

// Destructor
Serializer::~Serializer() {}

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
