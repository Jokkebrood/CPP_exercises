#pragma once

#include <string>
#include <iostream>

class Data
{
	public:
		// Constructor
		Data(std::string name, int number, std::string address);
		Data();
		Data(Data &src);

		// Operator overload
		Data& operator=(Data& src);
	
		// Destructor
		~Data();

		// Getters
		std::string getName() const;
		int getNumber() const;
		std::string getAddress() const;
	private:
		// Objects
		std::string _name;
		int _number;
		std::string _address;
};

std::ostream &operator<<(std::ostream &os, Data const &src);
