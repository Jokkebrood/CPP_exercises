#pragma once

template<typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(Array &src);

		// Destuctor
		~Array();

		// Operator overload
		Array operator=(Array &src);

		// Getters
		getArray();

		// Functions
	private:
		T array[];
};
