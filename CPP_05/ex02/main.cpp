#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm shrub("bush");
	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 150);
	try
	{
		employee.signAForm(shrub);
		std::cout << shrub;
		shrub.targetFunction(boss);
		shrub.targetFunction(employee);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "oh no" << std::endl;
	}
	return 0;
}
