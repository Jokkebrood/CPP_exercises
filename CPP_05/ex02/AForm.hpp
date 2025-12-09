#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(AForm &src);
		AForm(std::string name, int signGrade, int execGrade);
		~AForm();

		AForm operator=(AForm &src);

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

		class BothTooLow : public std::exception
		{
			public:
				BothTooLow(Bureaucrat &bur, AForm &form);
				virtual ~BothTooLow() throw() {}
				virtual const char *what() const throw();
			private:
				std::string _message;
		};

		class SignTooLow : public std::exception
		{
			public:
				SignTooLow(Bureaucrat &bur, AForm &form);
				virtual ~SignTooLow() throw() {}
				virtual const char *what() const throw();
			private:
				std::string _message;
		};

		class ExecTooLow : public std::exception
		{
			public:
				ExecTooLow(Bureaucrat &bur, AForm &form);
				virtual ~ExecTooLow() throw() {}
				virtual const char *what() const throw();
			private:
				std::string _message;
		};

	private:
		const std::string _name;
		bool _signature;
		const int _signGrade;
		const int _execGrade;
};

std::ostream &operator<<(std::ostream & os, AForm const &other);
