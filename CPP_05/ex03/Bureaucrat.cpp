#include "Bureaucrat.hpp"
#include "AForm.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS ******************************/

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat() : _name("Borig office man") ,_grade(75) {}

Bureaucrat::Bureaucrat(Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

/********************************* OPERATORS *************************************/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

void Bureaucrat::operator++(int)
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::operator--(int)
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

std::ostream &operator<<(std::ostream & os, Bureaucrat const &src)
{
	os << src.getName() << ",  bureaucrat grade " << src.getGrade();
	return os;
}

/***************************** GETTERS & SETTERS ********************************/

int Bureaucrat::getGrade() const { return _grade; }

std::string Bureaucrat::getName() const { return _name; }

/*********************************** OTHER *************************************/

void Bureaucrat::signAForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm& form)
{
	form.execute(*this);
}
