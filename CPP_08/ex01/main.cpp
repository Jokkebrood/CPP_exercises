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

	Span large = Span(11000);
	for (int i = 0; i < (11000 * 5); i += 5)
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

	Span sp2(5);
	sp2.multiAdd(5, 10, 15, 20, 25, 56);

	Span sp3(5);
	std::vector<int> v;
	v.push_back(4);
	v.push_back(24);
	v.push_back(17);
	v.push_back(70);
	v.push_back(1);

	sp3.multiAdd(v);
	return 0;
}
