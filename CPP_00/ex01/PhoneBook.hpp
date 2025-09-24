#pragma once

#include "Contact.hpp"
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <vector>

#define BOLD "\e[1m"
#define END_BOLD "\e[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END_COLOR "\033[0m"

#define MAX_CONTACT 3

class	PhoneBook {
	private:
		int		index;
		Contact	contact[MAX_CONTACT];
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
		void	addInfo(std::string &info, const std::string &message);
		void	displayIndexNr(int i);
		void	displayContactInfo(std::string info);
		void	printField(std::string field_name, std::string field, int length);
		void	selectContact();
		int		checkIfContactEmpty(int indexToCheck);
		int		longestField(int i);
};
