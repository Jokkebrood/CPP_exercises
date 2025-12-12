#pragma once

#include "AForm.hpp"
#include <fstream>
#include <cstring>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(ShrubberyCreationForm &src);
		
		const std::string getTarget() const;

		void execute(Bureaucrat &bur);
	private:
		const std::string _target;
};
