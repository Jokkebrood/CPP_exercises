#include <algorithm>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

#define MAX_CONTACT 3
#define BOLD "\e[1m"
#define END_BOLD "\e[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END_COLOR "\033[0m"

class	contact
{
	public:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

class	phonebook
{
	public:
	contact	contact[MAX_CONTACT];
};

void	add_contact(contact &contact);
void	search(contact contact[MAX_CONTACT]);
