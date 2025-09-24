#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}
PhoneBook::~PhoneBook() {}

int	PhoneBook::checkIfContactEmpty(int indexToCheck) {
	if (contact[indexToCheck].getFirstName().empty())
		return (1);
	return (0);
}

void	PhoneBook::addInfo(std::string &info, const std::string &message) {
	std::cout << message;
	if (!std::getline(std::cin, info))
		exit (1);
	while (!info.empty() && isspace(info[0]))
		info.erase(info.begin());
	while (info.empty())
	{
		std::cout << RED << "INVALID INPUT\n" << END_COLOR
			<< message;
		if (!std::getline(std::cin, info))
			exit (1);
	}
	if (message == "Enter phone number: ") {
		while (info.find_first_not_of("0123456789") != std::string::npos
			|| info.empty()) {
			std::cout << RED << "INVALID INPUT\n" << END_COLOR
			<< message;
			std::getline(std::cin, info);
			while (!info.empty() && isspace(info[0]))
				info.erase(info.begin());
		}
	}
	std::replace(info.begin(), info.end(), '\t', ' ');
}

void	PhoneBook::addContact() {
	std::string first, last, nick, phone, secret;
	
	addInfo(first, "Enter first name: ");
	addInfo(last, "Enter last name: ");
	addInfo(nick, "Enter nickname: ");
	addInfo(phone, "Enter phone number: ");
	addInfo(secret, "Enter darkest secret: ");

	contact[index] = Contact(first, last, nick, phone, secret, index + 1);
	index = (index + 1) % MAX_CONTACT;
	std::cout << GREEN
	<< "╔═══════════════════════════════╗\n"
	   "║ CONTACT WAS SUCCESFULLY ADDED ║\n"
	   "╚═══════════════════════════════╝\n" << END_COLOR;
}


void	PhoneBook::displayContactInfo(std::string info) {
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

int	PhoneBook::longestField(int i) {
	int	longest = 0;

	longest = contact[i].getFirstName().length();
	if ((int)contact[i].getLastName().length() > longest)
		longest = contact[i].getLastName().length();
	if ((int)contact[i].getNickName().length() > longest)
		longest = contact[i].getNickName().length();
	if ((int)contact[i].getPhoneNumber().length() > longest)
		longest = contact[i].getPhoneNumber().length();
	if ((int)contact[i].getDarkestSecret().length() > longest)
		longest = contact[i].getDarkestSecret().length();
	return (longest);
}

void	PhoneBook::printField(std::string field_name,
			std::string field, int length) {
	std::cout << "║" << field_name << "│" << field;
	for (int i = length - field.length(); i > 0; i--)
		std::cout << " ";
	std::cout << "║" << std::endl;
}

void	PhoneBook::displayIndexNr(int i) {
	int		length = longestField(i);
	std::string line;

	for (int i = 0; i < length; i++)
		line += "═";
	std::cout << "╔══════════════╤" << line << "╗" << std::endl;
	printField("first name    ", contact[i].getFirstName(), length);
	printField("last name     ", contact[i].getLastName(), length);
	printField("nickname      ", contact[i].getNickName(), length);
	printField("phone number  ", contact[i].getPhoneNumber(), length);
	printField("darkest secret", contact[i].getDarkestSecret(), length);
	std::cout << "╚══════════════╧" << line << "╝" << std::endl;
}

void	PhoneBook::selectContact() {
	std::string	input;

	std::cout << "Choose a contact to view: ";
	std::getline(std::cin, input);
	int	i = input[0] - '0' - 1;
	while (!(i >= 0 && i < MAX_CONTACT) ||
		input.length() != 1 || checkIfContactEmpty(i)) {
		std::cout << RED << "INVALID INPUT\n" << END_COLOR
		<< "Choose a contact to view: ";
		std::getline(std::cin, input);
		i = input[0] - '0' - 1;
	}
	displayIndexNr(i);
}

void	PhoneBook::searchContact() {
	std::string	input;
	std::cout << BOLD << "╔══════════════════════════════════════╗\n"
	"║          LIST OF CONTACTS            ║\n"
	"╠═════╤══════════╤══════════╤══════════╣\n"
	"║index│first name│last name │nickname  ║\n"
	"╠═════╪══════════╪══════════╪══════════╣\n" << END_BOLD;
	for (int i = 0; i < MAX_CONTACT && !contact[i].getFirstName().empty(); i++) {
		std::cout << "║  " << contact[i].getIndex() << "  ";
		displayContactInfo(contact[i].getFirstName());
		displayContactInfo(contact[i].getLastName());
		displayContactInfo(contact[i].getNickName());
		std::cout << "║\n";
		if (i + 1 < MAX_CONTACT && !contact[i + 1].getFirstName().empty())
			std::cout << "╟─────┼──────────┼──────────┼──────────╢\n";
	}
	std::cout << "╚═════╧══════════╧══════════╧══════════╝\n";
	selectContact();
}
