#include "AForm.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS ******************************/

AForm::AForm() : _name("file"), _signature(false), _signGrade(75), _execGrade(75) {}

AForm::AForm(AForm &src)
	: _name(src._name), _signature(src._signature), _signGrade(src._signGrade),
	_execGrade(src._execGrade) {}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _signature(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150)
		throw AForm::GradeTooLowException();
	else if (execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

/********************************* OPERATORS *************************************/

AForm AForm::operator=(AForm &src)
{
	if (this != &src)
		this->_signature = src._signature;
	return *this;
}

std::ostream &operator<<(std::ostream & os, AForm const &src)
{
	os << "AForm name: " << src.getName() << "\nExecution grade: " << src.getExecGrade()
	<< "\nSign grade: " << src.getSignGrade() << std::endl;
	return os;
}

/***************************** GETTERS & SETTERS ********************************/

std::string AForm::getName() const { return _name; }

bool AForm::getSignature() const { return _signature; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecGrade() const { return _execGrade; }

/*********************************** OTHER *************************************/

AForm::SignTooLow::SignTooLow(Bureaucrat &bur, AForm &form)
	: _message(bur.getName() + " couldn't sign " + form.getName()
	+ " because their sign grade is too low" + "\n") {}

AForm::ExecTooLow::ExecTooLow(Bureaucrat &bur, AForm &form)
	: _message(bur.getName() + " couldn't sign " + form.getName()
	+ " because their execution grade is too low" + "\n") {}

AForm::BothTooLow::BothTooLow(Bureaucrat &bur, AForm &form)
	: _message(bur.getName() + " couldn't sign " + form.getName()
	+ " because their execution and sign grade are too low" + "\n") {}

const char *AForm::BothTooLow::what() const throw()
{
	return _message.c_str();
}

const char *AForm::SignTooLow::what() const throw()
{
	return _message.c_str();
}

const char *AForm::ExecTooLow::what() const throw()
{
	return _message.c_str();
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > _signGrade && bur.getGrade() > _execGrade)
		throw AForm::BothTooLow(bur, *this);
	else if (bur.getGrade() > _signGrade)
	{
		throw AForm::SignTooLow(bur, *this);
	}
	else if (bur.getGrade() > _execGrade)
		throw AForm::ExecTooLow(bur, *this);
	std::cout << bur.getName() << " signed " << _name << std::endl;
	_signature = true;
}
