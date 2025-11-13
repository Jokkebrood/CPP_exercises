#pragma once

#include "iostream"
#include "string"

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		Brain& operator=(const Brain &src);
		~Brain();
	protected:
		std::string _ideas[100];
};
