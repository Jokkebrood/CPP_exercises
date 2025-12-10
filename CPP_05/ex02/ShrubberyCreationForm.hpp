#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm operator=(ShrubberyCreationForm &src);
		
		std::string &getTarget() const;

		void targetFunction(Bureaucrat &bur);
	private:
		const std::string _target;
};
