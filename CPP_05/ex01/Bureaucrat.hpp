#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat 
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &src);
		void operator++(int);
		void operator--(int);

		int getGrade() const;
		std::string getName() const;

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
