#include "PhoneBook.hpp"

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

int	main() {
	std::string	input;
	PhoneBook	phonebook;

	info();
	while (std::getline(std::cin, input)) {
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH") {
			if (phonebook.checkIfContactEmpty(0))
				std::cout << RED << "There are no contacts to search yet"
					<< END_COLOR << std::endl;
			else
				phonebook.searchContact();
		}
		else if (input == "EXIT")
			exit (0);
	}
}
