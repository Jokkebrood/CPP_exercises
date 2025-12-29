#include "Bureaucrat.hpp"

/************************* CONSTRUCTORS & DESTRUCTORS ******************************/

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat input constructor. Name: " << _name << std::endl;
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

Bureaucrat::Bureaucrat() : _name("Borig office man") ,_grade(75)
{
	std::cout << "Bureaucrat default constructor. Name: " << _name << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor. Name: " << _name << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destuctor. Name: " << _name << std::endl;
}

/********************************* OPERATORS *************************************/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

void Bureaucrat::lowerLevel()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::raiseLevel()
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

/*************************** EXCEPTION FUNCTIONS ********************************/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "ERROR: Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "ERROR: Grade too low";
}
