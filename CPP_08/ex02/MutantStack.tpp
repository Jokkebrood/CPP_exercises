#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack default constructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{
	std::cout << "MutantStack copy constructor" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src)
{
	std::cout << "MutantStack operator overload" << std::endl;
	if (this != &src)
		std::stack<T>::operator=(src);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor" << std::endl;
}
// The c is defined in the standard, it stands for container.
// It is the string, stack, etc. of data saved in the container.

//ITERATOR
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

//CONST ITERATOR

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

//REVERSE ITERATOR

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

//CONST REVERSE ITERATOR

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}

#endif
