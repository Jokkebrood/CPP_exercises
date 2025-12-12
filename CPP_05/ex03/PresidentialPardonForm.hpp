#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm &src);
		
		const std::string getTarget() const;

		void execute(Bureaucrat &bur);
	private:
		const std::string _target;
};
