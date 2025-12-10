#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShubberyCreationForm", 145, 137), _target(src.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::targetFunction(Bureaucrat& bur)
{
	bur.signAForm(*this);
	std::cout << "shrubbery target function: " << _target << std::endl;
}
