#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int getNumberInput() {
    std::string grade;
    while (true) {
        if (!std::getline(std::cin, grade)) { // EOF or error
            std::cout << std::endl << "Input ended unexpectedly." << std::endl;
            return -1; // or some sentinel value indicating EOF
        }

        bool allDigits = true;
        for (std::string::size_type i = 0; i < grade.size(); ++i) {
            if (!std::isdigit(grade[i])) {
                allDigits = false;
                break;
            }
        }

        if (allDigits && !grade.empty()) {
            int value;
            std::istringstream iss(grade);
            iss >> value;
            return value;
        } else {
            std::cout << "Invalid input. Please enter numbers only: ";
        }
    }
}

int main()
{
	std::string burName;

	std::string formName;

	std::cout << "Choose name for your bureaucrat: ";
	std::getline(std::cin, burName);
	std::cout << "Choose grade for bureaucrat: ";
	int grade = getNumberInput();
	try
	{
		Bureaucrat bur(burName, grade);
		std::cout << "Choose name for your form: ";
		std::getline(std::cin, formName);
		std::cout << "Choose sign grade for form: ";
		int sign = getNumberInput();
		std::cout << "Choose execution grade for form: ";
		int exec = getNumberInput();
		try
		{
			Form form(formName, sign, exec);
			std::cout << std::endl;
			std::cout << "RESULT OF YOUR BUREAUCRAT TRYING TO SIGN YOUR FORM" << std::endl;
			std::cout << std::endl;
			bur.signForm(form);	
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
