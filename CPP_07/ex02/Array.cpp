#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() _n(0);
{
	std::cout << "Array default constructor" std::endl;
	T array[] = new T[];
}

template <typename T>
Array<T>::Array(int n) : _n(n);
{
	std::cout << "Array default constructor" std::endl;
	T array[n] = new T[n];
}

Array<T>::Array(Array const &src)
{
	_n = src._n;
	for (int i = 0; i < n; i++)
	{
		array[i] = new Array(*src.array);
	}
}
