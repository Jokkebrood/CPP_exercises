#include "Form.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS ******************************/

Form() : _name("file"), _signGrade(75), _execGrade(75) {}

Form(&src)
	: _name(src._name), _signGrade(src.signGrade),
	_execGrade(src.ExecGrade), _signature(src._signature) {}

Form(std::string name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
	else if (execGrade < 1)
		throw Form::GradeTooHighException();
	else if (execGrade > 150)
		throw Form::GradeTooLowException();
}

~Form() {}

/********************************* OPERATORS *************************************/

Form Form::operator=(Form &src)
{
	if (this != &src)
		this->_signature = src._signature;
	return *this;
}

/***************************** GETTERS & SETTERS ********************************/

std::string Form::getName() const { return _name }

bool Form::getSignature() const { return _signature }

int Form::getSignGrade() const { return _signGrade }

int Form::getExecGrade() const { return _execGrade }

/*********************************** OTHER *************************************/

void beSigned(Bureaucrat &bur)
{
	if (bur._grade >= _signGrade)
	{
		if (bur._grade >= _execGrade)
		{
			std::cout << bur._name << " signed " << _name << std::endl;
			_signature = true;
		}
		else
		{
			std::cout << bur._name << " couldn't sign " << _name
			<< " because required execution grade is " << _execGrade
			<< " and " << bur._name << "'s is grade " << bur._grade
			<< std::endl;
		}
	}
	else
	{
		if (bur._grade < _execGrade)
		{
			std::cout << bur._name << " couldn't sign " << _name
			<< " because required grade to sign is " << _execGrade
			<< " and " << bur._name << "'s is grade " << bur._grade
			<< std::endl;
		}
		else
		{
			std::cout << bur._name << " couldn't sign " << _name
			<< " because " << bur._name << "'s is grade is too low on both counts"
			<< std::endl << bur._name << "'s grade: " << bur._grade
			<< std::endl << "Required sign grade: " << _signGrade
			<< std::endl << "Required execution grade: " << _execGrade << std::endl;
		}
	}
}
