#pragma once

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(&src);
		Form(std::string name, int signGrade, int execGrade);
		~Form();

		Form operator=(Form &src);

		std::string getName() const;
		bool getSignature() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &bur);

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

		class bothTooLow : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class SignTooLow : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class ExecTooLow : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		bool _signature = false;
		const int _signGrade;
		const int _execGrade;
}
