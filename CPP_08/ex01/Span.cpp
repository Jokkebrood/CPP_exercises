#include "Span.hpp"

//Constructors

Span::Span() : N(0)
{
	std::cout << "Span default constructor" << std::endl;
}

/*
Span::Span(Span &src) : N(src.N)
{
	std::cout << "Span copy constructor" << std::endl;
}
*/

Span::Span(unsigned int n) : N(n)
{
	std::cout << "Span input constructor" << std::endl;
}

//destructor

Span::~Span()
{
	std::endl << "Span destructor" << setd::endl;
}

//functions

void addNumber(int nr)
{
	if (
	list.push_back(nr);
}
