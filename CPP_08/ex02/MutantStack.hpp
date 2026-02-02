#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>

#define red "\x1B[31m"
#define blue "\x1B[34m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define reset "\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		//constructors & destructor
		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();

		//operator overload
		MutantStack& operator=(const MutantStack &src);

		// These are aliases for the imbeded iterators hidden in the stack container
		// It is the only way to access the iterator in stack
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator const_reverse_iterator;

		//functions
		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();

		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#endif
