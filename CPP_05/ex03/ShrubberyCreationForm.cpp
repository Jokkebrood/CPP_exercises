#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm input constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		// Only const objects nothing to copy
	}
	return *this;
}

const std::string ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat& bur)
{
	try
	{
		bur.signAForm(*this);
		std::string file = _target + "_shrubbery";
		std::ofstream outfile(file.c_str());
		outfile <<
			"            	,@@@@@@@,\n"
			"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			"       |o|        | |         | |\n"
			"       |.|        | |         | |\n"
			"    _\\/ ._\\/_/___/  ,\\_\\/___\\/.  \\_/__/_";
		outfile.close();
	}
	catch(AForm::BothTooLow &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(AForm::SignTooLow &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(AForm::ExecTooLow &e)
	{
		std::cout << e.what() << std::endl;
	}
}
