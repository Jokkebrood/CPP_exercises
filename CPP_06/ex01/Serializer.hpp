#pragma once

#include <stdint.h>
#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);

		static Data* deserialize(uintptr_t raw);
	private:
		// Constructors
		Serializer();
		Serializer(Serializer &src);

		// Destructor
		~Serializer();

		// Overload operator
		Serializer &operator=(Serializer &src);
};
