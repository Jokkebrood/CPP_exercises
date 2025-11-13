#include "Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
}

Brain& Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

Brain::~Brain() {}
