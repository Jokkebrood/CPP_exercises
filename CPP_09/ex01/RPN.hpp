#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream> // std::istringstream
#include <cstdlib> // atof()

#define red "\x1B[31m"
#define blue "\x1B[34m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define reset "\033[0m"

class RPN
{
	private:
		// Constructors
		RPN();
		RPN(RPN &src);

		// Objects
		std::stack<double> stack;

		// Functions
		void executeArithmic(std::string op);
	public:
		// Constructors
		RPN(std::string input);

		// Destructor
		~RPN();
		
		// Operator
		RPN& operator=(RPN &src);
};
#endif
