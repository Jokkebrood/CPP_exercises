#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm input constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	if (this != &src)
	{
		// Only const objects nothing to copy
	}
	return *this;
}

const std::string PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat& bur)
{
	try
	{
		bur.signAForm(*this);
		std::cout << _target
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
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
