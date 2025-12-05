#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "This one increments too low" << std::endl;
		Bureaucrat bureaucrat("Mr Low", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat--;
		std::cout << bureaucrat << std::endl;
		bureaucrat++;
		std::cout << bureaucrat << std::endl;
		bureaucrat++;
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "This one initializes too low" << std::endl;
		Bureaucrat bureaucrat("Mr Low", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "This one initializes too high" << std::endl;
		Bureaucrat bureaucrat("Mr High", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat++;
		std::cout << bureaucrat << std::endl;
		bureaucrat--;
		std::cout << bureaucrat << std::endl;
		bureaucrat--;
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "This one initializes too high" << std::endl;
		Bureaucrat bureaucrat("Mr High", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		// For evaluator to try something if they want
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
