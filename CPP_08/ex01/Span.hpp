#ifndef SPAN_HPP
#define SPAN_HPP

#include <cmath>
#include <vector>

template <typename T>
class Span
{
	private:
		unsigned int N;
		std::vector<int> list;
	public:
		//constructors
		Span();
//		Span(Span &src);
		Span(unsigned int n);

		//destructor
		~Span();
	
		//copy assignment operator
		Span operator=(Span &src);

		//functions
		void addNumber(int nr);	

		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif
