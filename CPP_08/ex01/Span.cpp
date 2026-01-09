#include "Span.hpp"

//Constructors

Span::Span() : N(0)
{
	std::cout << "Span default constructor" << std::endl;
}

Span::Span(const Span &src) : N(src.N), list(src.list)
{
	std::cout << "Span copy constructor" << std::endl;
}

Span::Span(unsigned int n) : N(n)
{
	std::cout << "Span input constructor" << std::endl;
}

//destructor

Span::~Span()
{
	std::cout << "Span destructor" << std::endl;
}

//operator overload functions

Span& Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->N = src.N;
		this->list = src.list;
	}
	return *this;
}

//functions

void Span::addNumber(int nr)
{
	if (list.size() >= N)
		throw std::overflow_error("Container is full. Cannot add another integer");
	list.push_back(nr);
}

int diff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

unsigned int Span::shortestSpan() const
{
	int shortest = 0;

	for (size_t i = 1; i < list.size(); i++)
	{
		if (diff(list[i], list[i - 1]) < shortest)
			shortest = diff(list[i], list[i - 1]);
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	int longest = 0;

	for (size_t i = 1; i < list.size(); i++)
	{
		if (diff(list[i], list[i - 1]) > longest)
			longest = diff(list[i], list[i - 1]);
	}
	return longest;
}
