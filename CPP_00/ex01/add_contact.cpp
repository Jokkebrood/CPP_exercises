#include "phonebook.hpp"

int	isdigit_string(std::string info)
{
	if (info.empty())
	{
		std::cout << RED << "Empty input\n"
		"Please provide valid input: " << END_COLOR;
		return (0);
	}
	for (int i = 0; info[i]; i++)
	{
		if (!isdigit(info[i]) || info.empty())
		{
			std::cout << RED << "phone numbers must only contain numbers\n"
			"please provide a valid phone number: " << END_COLOR;
			return (0);
		}
	}
	return (1);
}

void	add_info(std::string &info, std::string message)
{
	std::cout << message;
	if (!std::getline(std::cin, info))
		exit(1);
	while (!info.empty() && isspace(info[0]))
		info.erase(info.begin());
	if (message.compare("Enter phone number: ") == 0)
	{
		while (!isdigit_string(info) && std::getline(std::cin, info))
		{
			while (!info.empty() && isspace(info[0]))
				info.erase(info.begin());
		}
	}
	else if (info.length() == 0)
	{
		std::cout << RED << "Empty input\n"
		"Please provide valid input: " << END_COLOR;
		while (info.length() == 0 && std::getline(std::cin, info))
			while (!info.empty() && isspace(info[0]))
				info.erase(info.begin());
			if (info.empty())
			{
				std::cout << RED << "Empty input\n"
					"Please provide valid input: " << END_COLOR;
			}
		}
	}
	std::replace(info.begin(), info.end(), '\t', ' ');
}

void	add_contact(contact &contact)
{
	add_info(contact.first_name , "Enter first name: ");
	add_info(contact.last_name , "Enter last name: ");
	add_info(contact.nickname , "Enter nickname: ");
	add_info(contact.phone_number , "Enter phone number: ");
	add_info(contact.darkest_secret , "Enter darkest secret: ");
	std::cout << GREEN << "╔═════════════════════════════╗\n"
	"║CONTACT WAS SUCCESFULLY ADDED║\n"
	"╚═════════════════════════════╝\n" << END_COLOR;
}
