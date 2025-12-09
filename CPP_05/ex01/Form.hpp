#pragma once

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(Form &src);
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

		class BothTooLow : public std::exception
		{
			public:
				BothTooLow(Bureaucrat &bur, Form &form);
				virtual ~BothTooLow() throw() {}
				virtual const char *what() const throw();
			private:
				std::string _message;
		};

		class SignTooLow : public std::exception
		{
			public:
				SignTooLow(Bureaucrat &bur, Form &form);
				virtual ~SignTooLow() throw() {}
				virtual const char *what() const throw();
			private:
				std::string _message;
		};

		class ExecTooLow : public std::exception
		{
			public:
				ExecTooLow(Bureaucrat &bur, Form &form);
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
