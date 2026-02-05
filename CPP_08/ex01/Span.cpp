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

void Span::multiAdd(unsigned int count, ...)
{
	if (list.size() + count > N)
		throw std::overflow_error("Container is full. Cannot add another integer");
	va_list va;
	va_start(va, count);	
	for (unsigned int i = 0; i < count; i++)
		addNumber(va_arg(va, int));
	va_end(va);
}

void Span::multiAdd(std::vector<int> v)
{
	std::vector<int>::iterator begin = v.begin();
	std::vector<int>::iterator end = v.end();

	if (list.size() + std::distance(begin, end) > N)
		throw std::overflow_error("Container is full. Cannot add another integer");
	list.insert(list.end(), begin, end);
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
	if (list.size() < 2)
		throw std::length_error("Cannot perform comparison on container with less then 2 values");

	unsigned int shortest = std::floor(diff(list[0], list[1]));

	for (size_t i = 0; i < list.size(); i++)
	{
		for (size_t j = 0; j < list.size(); j++)
		{
			if (std::floor(diff(list[i], list[j])) < shortest && i != j)
				shortest = diff(list[i], list[j]);
		}
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (list.size() < 2)
		throw std::length_error("Cannot perform comparison on container with less then 2 values");

	unsigned int longest = std::floor(diff(list[0], list[1]));

	for (size_t i = 0; i < list.size(); i++)
	{
		for (size_t j = 0; j < list.size(); j++)
		{
			if (std::floor(diff(list[i], list[j])) > longest)
				longest = diff(list[i], list[j]);
		}
	}
	return longest;
}
