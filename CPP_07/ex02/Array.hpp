#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(Array const &src);

		Array(int n);
		// Destuctor
		~Array();

		// Operator overload
		Array& operator=(Array const &src);
		T& operator[](unsigned int i);

		// Getters
		T* getArray() const;

		// Functions
	private:
		T *array;
		unsigned int _n;
};

#include "Array.tpp"

#endif
