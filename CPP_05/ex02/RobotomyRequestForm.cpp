#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	if (this != &src)
	{
		// Only const objects nothing to copy
	}
	return *this;
}

const std::string RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat& bur)
{
	try
	{
		bur.signAForm(*this);
		std::time_t now = std::time(NULL);
		std::tm *t = std::localtime(&now);
		if (t->tm_sec % 2 == 0)
		{
			std::cout << _target
			<< " has been successfully robotomized." << std::endl;
		}
		else
		{
			std::cout << "ERROR: robotomization of "
			<< _target << " was unsuccesfull."
				<< std::endl;
		}
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
