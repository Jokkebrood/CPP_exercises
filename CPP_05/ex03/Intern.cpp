#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" <<std::endl;
}

Intern::Intern(Intern &src)
{
	std::cout << "Intern copy constructor" <<std::endl;
	(void)src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" <<std::endl;
}

Intern& Intern::operator=(Intern &src)
{
	if (this != &src)
	{
		// Intern has no objects to copy
	}
	return *this;
}

AForm *createShrub(const std::string &target)
{ 
	return new ShrubberyCreationForm(target);
}

AForm *createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *createRobot(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string error = "ERROR: " + target + " is not a valid form";
    std::map<std::string, AForm *(*)(const std::string &)> formMap;

    formMap["shrubbery creation"] = &createShrub;
    formMap["robotomy request"]  = &createRobot;
    formMap["presidential pardon"] = &createPardon;

    std::map<std::string, AForm *(*)(const std::string &)>::iterator it
	= formMap.find(name);
    if (it != formMap.end())
        return it->second(target);
    throw std::runtime_error(error.c_str());
}
