#pragma once

#include "AForm.hpp"
#include <map>

class Intern
{
	public:
		Intern();
		Intern(Intern &src);
		~Intern();

		Intern& operator=(Intern &src);

		AForm *makeForm(const std::string &name, const std::string &target);
};
