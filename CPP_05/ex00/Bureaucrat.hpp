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

		int getGrade() const;
		void raiseLevel();
		void lowerLevel();
		std::string getName() const;

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);
