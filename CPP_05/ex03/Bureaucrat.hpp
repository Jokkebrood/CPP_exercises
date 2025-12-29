#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat 
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &src);
		void lowerLevel();
		void raiseLevel();

		int getGrade() const;
		std::string getName() const;

		void signAForm(AForm &form);

		void executeForm(AForm& form);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "ERROR: Grade too low";
				}
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "ERROR: Grade too high";
				}
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);
