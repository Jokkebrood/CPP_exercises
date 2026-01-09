#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span large = Span(150000);
	for (int i = 0; i < (150000 * 5); i += 5)
		large.addNumber(i);
	std::cout << large.shortestSpan() << std::endl;
	std::cout << large.longestSpan() << std::endl;

	try
	{
		Span ov = Span(2);
		ov.addNumber(6);
		ov.addNumber(3);
		ov.addNumber(17);
		ov.addNumber(9);
		ov.addNumber(11);
		std::cout << ov.shortestSpan() << std::endl;
		std::cout << ov.longestSpan() << std::endl;
	}
	catch (std::overflow_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span one = Span(1);
		one.addNumber(1);
		std::cout << one.shortestSpan() << std::endl;
		std::cout << one.longestSpan() << std::endl;
	}
	catch (std::length_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
