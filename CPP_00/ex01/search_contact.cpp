#include "phonebook.hpp"

void	display_contact_info(std::string info)
{
	std::cout << "│";
	if (info.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << info[i];
		std::cout << ".";
	}
	else
	{
		for (int i = info.length(); i < 10; i++)
			std::cout << " ";
		std::cout << info;
	}
}

int	longest_field(contact contact)
{
	int	longest = 0;

	longest = contact.first_name.length();
	if ((int)contact.last_name.length() > longest)
		longest = contact.last_name.length();
	if ((int)contact.nickname.length() > longest)
		longest = contact.nickname.length();
	if ((int)contact.phone_number.length() > longest)
		longest = contact.phone_number.length();
	if ((int)contact.darkest_secret.length() > longest)
		longest = contact.darkest_secret.length();
	return (longest);
}

void	print_field(std::string field_name, std::string field, int length)
{
	std::cout << "║" << field_name << "│" << field;
	for (int i = length - field.length(); i > 0; i--)
		std::cout << " ";
	std::cout << "║\n";
}

void	display_index_nr(contact contact)
{
	int	length = longest_field(contact);

	std::cout << "╔══════════════╤";
	for (int i = length; i != 0; i--)
		std::cout << "═";
	std::cout << "╗\n";
	print_field("first name    ", contact.first_name, length);
	print_field("last name     ", contact.last_name, length);
	print_field("nickname      ", contact.nickname, length);
	print_field("phone number  ", contact.phone_number, length);
	print_field("darkest secret", contact.darkest_secret, length);
	std::cout << "╚══════════════╧";
	for (int i = length; i != 0; i--)
		std::cout << "═";
	std::cout << "╝\n";
}

void	search(contact contact[MAX_CONTACT])
{
	std::string	input;
	int			index_nr = -1;
	std::cout << BOLD << "╔══════════════════════════════════════╗\n"
	"║          LIST OF CONTACTS            ║\n"
	"╠═════╤══════════╤══════════╤══════════╣\n"
	"║index│first name│last name │nickname  ║\n"
	"╠═════╪══════════╪══════════╪══════════╣\n" << END_BOLD;
	for (int i = 0; i < MAX_CONTACT && !contact[i].first_name.empty() != 0; i++)
	{
		std::cout << "║  " << contact[i].index << "  ";
		display_contact_info(contact[i].first_name);
		display_contact_info(contact[i].last_name);
		display_contact_info(contact[i].nickname);
		std::cout << "║\n";
		if (i + 1 < MAX_CONTACT && !contact[i + 1].first_name.empty())
			std::cout << "╟─────┼──────────┼──────────┼──────────╢\n";
	}
	std::cout << "╚═════╧══════════╧══════════╧══════════╝\n";
	std::cout << "Please enter index number: ";
	while (std::cin >> input)
	{
		if (input.length() == 1)
			index_nr = input[0] - '0' - 1;
		if (index_nr < MAX_CONTACT && index_nr >= 0
			&& contact[index_nr].first_name.length() != 0)
			break;
		else
			std::cout << BOLD << RED << "INVALID INPUT\n"
			<< END_COLOR << END_BOLD
			<< "please enter a valid index number: ";
	}
	display_index_nr(contact[index_nr]);
}
