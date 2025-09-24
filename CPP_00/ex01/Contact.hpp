#pragma once

#include <string>

class	Contact {
	private:
		int			Index;
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

	public:
		int			getIndex() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		// Constructor
		Contact();
		Contact(std::string first,
			std::string last, std::string nick,
			std::string phone, std::string secret, int index);
		//Destructor
		~Contact();
};
