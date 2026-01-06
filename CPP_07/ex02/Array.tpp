#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _n(0)
{
	std::cout << "Array default constructor" << std::endl;
	array = NULL;
}

template <typename T>
Array<T>::Array(int n) : _n(n)
{
	std::cout << "Array default constructor" << std::endl;
	array = new T[n];
}

template <typename T>
Array<T>::Array(Array const &src) : array(new T[src._n]), _n(src._n)
{
	for (unsigned int i = 0; i < _n; i++)
		array[i] = src.array[i];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor" << std::endl;
	delete[] array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const &src)
{
	if (*this != src)
	{
		_n = src._n;
		delete[] array;
		array = new T[src._n];
		for (unsigned int i = 0; i < _n; i++)
			array[i] = src.array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i < _n)
		throw std::invalid_argument("this object does not exist");
	return array[i];
}

template <typename T>
T* Array<T>::getArray() const
{
	return array;
}

#endif
