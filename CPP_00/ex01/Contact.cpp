#include "Contact.hpp"

int	Contact::getIndex() const {
	return (Index);
}
std::string	Contact::getFirstName() const {
	return (FirstName);
}

std::string	Contact::getLastName() const {
	return (LastName);
}

std::string	Contact::getNickName() const {
	return (NickName);
}

std::string	Contact::getPhoneNumber() const {
	return (PhoneNumber);
}

std::string	Contact::getDarkestSecret() const {
	return (DarkestSecret);
}

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(std::string first, std::string last, std::string nick,
		std::string phone, std::string secret, int index) {
	Index = index;
	FirstName = first;
	LastName = last;
	NickName = nick;
	PhoneNumber = phone;
	DarkestSecret = secret;
}
