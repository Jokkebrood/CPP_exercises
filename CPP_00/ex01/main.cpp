#include "phonebook.hpp"

void	info()
{
	std::cout << "╔════════════════════════════════════════════╗\n"
	"║       THIS IS A DIGITAL PHONEBOOK          ║\n"
	"╠════════════════════════════════════════════╣\n"
	"║Write " << GREEN << "ADD" << END_COLOR <<
	" to save a new contact             ║\n"
	"║Write " << GREEN << "SEARCH" << END_COLOR <<
	" to search for existing contacts║\n"
	"║Write " << GREEN << "EXIT" << END_COLOR <<
	" to exit the program              ║\n"
	"╚════════════════════════════════════════════╝\n";
}


int	main()
{
	phonebook	phonebook;
	int			index = 0;
	std::string	input;
	info();
	while (std::getline(std::cin, input))
	{
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input.compare("EXIT") == 0)
			break;
		if (input.compare("ADD") == 0) {
			add_contact(phonebook.contact[index]);
			phonebook.contact[index].index = index + 1;
			index = (index + 1) % MAX_CONTACT;
		}
		if (input.compare("SEARCH") == 0)
		{
			if (phonebook.contact[0].first_name.length() == 0)
				std::cout << RED
				<< "There are no contacts to search yet\n" << END_COLOR;
			else
				search(phonebook.contact);
		}
	}
	return (0);
}
