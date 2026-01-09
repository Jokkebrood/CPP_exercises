#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>

class Span
{
	private:
		unsigned int N;
		std::vector<int> list;
	public:
		//constructors
		Span(unsigned int n);
		Span();
		Span(const Span &src);

		//destructor
		~Span();
	
		//copy assignment operator
		Span& operator=(const Span &src);

		//functions
		void addNumber(int nr);	

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif
