#pragma once

#include <iostream>
#include <string>

template<typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(Array &src);

		Array(int n);
		// Destuctor
		~Array();

		// Operator overload
		Array operator=(Array &src);

		// Getters
		getArray();

		// Functions
	private:
		T array[];
		int _n;
};
