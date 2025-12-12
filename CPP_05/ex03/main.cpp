#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
int main()
{
	RobotomyRequestForm bot("robot");
	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 150);
	
	std::cout << "2 bureaucrats have been created:" << std::endl;
	std::cout << std::endl;
	std::cout << employee << std::endl;
	std::cout << boss << std::endl;
	std::cout << std::endl;
	std::cout << "1 form has been created:" << std::endl;
	std::cout << std::endl;
	std::cout << bot;
	std::cout << std::endl;
	std::cout << "Employee tries to execute form:" << std::endl;
	std::cout << std::endl;
	bot.execute(employee);	
	std::cout << "Boss tries to execute form:" << std::endl;
	std::cout << std::endl;
	bot.execute(boss);
	return 0;
}
*/

/*
int main()
{
	ShrubberyCreationForm fern("plant");
	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 150);
	
	std::cout << "2 bureaucrats have been created:" << std::endl;
	std::cout << std::endl;
	std::cout << employee << std::endl;
	std::cout << boss << std::endl;
	std::cout << std::endl;
	std::cout << "1 form has been created:" << std::endl;
	std::cout << std::endl;
	std::cout << fern;
	std::cout << std::endl;
	std::cout << "Employee tries to execute form:" << std::endl;
	std::cout << std::endl;
	fern.execute(employee);	
	std::cout << "Boss tries to execute form:" << std::endl;
	std::cout << std::endl;
	fern.execute(boss);
	return 0;
}
*/

/*
int main()
{
	PresidentialPardonForm pardon("A person");
	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 150);
	
	std::cout << "2 bureaucrats have been created:" << std::endl;
	std::cout << std::endl;
	std::cout << employee << std::endl;
	std::cout << boss << std::endl;
	std::cout << std::endl;
	std::cout << "1 form has been created:" << std::endl;
	std::cout << std::endl;
	std::cout << pardon;
	std::cout << std::endl;
	std::cout << "Employee tries to execute form:" << std::endl;
	std::cout << std::endl;
	pardon.execute(employee);	
	std::cout << "Boss tries to execute form:" << std::endl;
	std::cout << std::endl;
	pardon.execute(boss);
	boss.executeForm(pardon);
	return 0;
}
*/

int main()
{
//	Bureaucrat boss("boss", 1);
	Intern intern;

	AForm *formA = intern.makeForm("shrubbery creation", "gardenA");
	AForm *formB = new ShrubberyCreationForm("gardenB");
	std::cout << *formA;
	std::cout << *formB;
	try
	{
		AForm *formC = intern.makeForm("bad input", "gardenC");
		std::cout << *formC;
		delete formC;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete formA;
	delete formB;
}
