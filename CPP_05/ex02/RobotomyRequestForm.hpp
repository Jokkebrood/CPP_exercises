#pragma once

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm &src);
		
		const std::string getTarget() const;

		void execute(Bureaucrat &bur);
	private:
		const std::string _target;
};
