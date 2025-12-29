#include "Form.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS ******************************/

Form::Form() : _name("file"), _signature(false), _signGrade(75), _execGrade(75)
{
	std::cout << "Default file constructor. Name: " << _name << std::endl;
}

Form::Form(Form &src)
	: _name(src._name), _signature(src._signature), _signGrade(src._signGrade),
	_execGrade(src._execGrade)
{
	std::cout << "File copy constructor. Name: " << _name << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _signature(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form input constructor. Nmae: " << _name << std::endl;
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
	else if (execGrade < 1)
		throw Form::GradeTooHighException();
	else if (execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "File destructor. Name: " << _name << std::endl;
}

/********************************* OPERATORS *************************************/

Form Form::operator=(Form &src)
{
	if (this != &src)
		this->_signature = src._signature;
	return *this;
}

std::ostream &operator<<(std::ostream & os, Form const &src)
{
	os << "Form name: " << src.getName() << "\nExecution grade: " << src.getExecGrade()
	<< "\nSign grade: " << src.getSignGrade() << std::endl;
	return os;
}

/***************************** GETTERS & SETTERS ********************************/

std::string Form::getName() const { return _name; }

bool Form::getSignature() const { return _signature; }

int Form::getSignGrade() const { return _signGrade; }

int Form::getExecGrade() const { return _execGrade; }

/*********************************** OTHER *************************************/

Form::SignTooLow::SignTooLow(Bureaucrat &bur, Form &form)
	: _message(bur.getName() + " couldn't sign " + form.getName()
	+ " because their grade is too low to sign\n") {}

Form::ExecTooLow::ExecTooLow(Bureaucrat &bur, Form &form)
	: _message(bur.getName() + " couldn't sign " + form.getName()
	+ " because their grade is too low to execute\n") {}

Form::BothTooLow::BothTooLow(Bureaucrat &bur, Form &form)
	: _message(bur.getName() + " couldn't sign " + form.getName()
	+ " because their grade is too low to execute or sign \n") {}

const char *Form::BothTooLow::what() const throw()
{
	return _message.c_str();
}

const char *Form::SignTooLow::what() const throw()
{
	return _message.c_str();
}

const char *Form::ExecTooLow::what() const throw()
{
	return _message.c_str();
}

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > _signGrade && bur.getGrade() > _execGrade)
		throw Form::BothTooLow(bur, *this);
	else if (bur.getGrade() > _signGrade)
	{
		throw Form::SignTooLow(bur, *this);
	}
	else if (bur.getGrade() > _execGrade)
		throw Form::ExecTooLow(bur, *this);
	std::cout << bur.getName() << " signed " << _name << std::endl;
	_signature = true;
}
