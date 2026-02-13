#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN& src) : stack(src.stack) {}

RPN::~RPN() {}

RPN::RPN(std::string input)
{
	std::string token;
	std::istringstream equation(input);
	while (getline(equation, token, ' '))
	{
		if (token.length() > 2 ||
			(token.length() == 2 && (token[0] != '-' || !isdigit(token[1]))))
			throw std::runtime_error(std::string(red) +
			"ERROR: invalid token ->\"" + token + '"' + std::string(reset));

		else if (token.length() == 2 || isdigit(token[0]))
			stack.push(atof(token.c_str()));

		else if (token.compare("-") || token.compare("+") || token.compare("/") || token.compare("*"))
			executeArithmic(token);

		else
			throw std::runtime_error(std::string(red) +
			"ERROR: invalid token ->\"" + token + '"' + std::string(reset));
	}
	if (stack.size() != 1)
		throw std::runtime_error(std::string(red) +
		"ERROR: invalid input" + std::string(reset));
	std::cout << stack.top() << std::endl;
}

void RPN::executeArithmic(std::string op)
{
	double a, b;
	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();
	if (op.compare("-") == 0)
		stack.push(a - b);
	else if (op.compare("+") == 0)
		stack.push(a + b);
	else if (op.compare("*") == 0)
		stack.push(a * b);
	else if (op.compare("/") == 0)
		stack.push(a / b);
}
