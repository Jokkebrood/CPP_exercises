#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string &target);
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShubberyCreationForm operator=(ShrubberyCreationForm &src);
	private:
}
