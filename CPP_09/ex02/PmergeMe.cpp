#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &src)
{
	*this = src;
}

PmergeMe::PmergeMe(int ac, char **input) : comparisons(0)
{
	if (ac < 3)
		throw std::runtime_error("Expects at least two strings of input");
	for (int i = 1; input[i]; i++)
		addList(input[i]);
	if (numbers.size() % 2 != 0)
	{
		leftover = numbers.back().back();
		numbers.pop_back();
	}
	while (numbers.size() != 1 && numbers.size() != 3)
		mergeSort();
}

PmergeMe::~PmergeMe() {}

const std::vector< std::list<int> > &PmergeMe::getNumbers() const
{
	return numbers;
}

const int &PmergeMe::getComparisons() const
{
	return comparisons;
}

// Takes pairs of lists inside the vector and merges them.
// The size of the last element of each list it will decide which one to append.
void PmergeMe::mergeSort()
{
	std::vector< std::list<int> >::iterator it = numbers.begin();
	std::vector< std::list<int> >::iterator temp = numbers.begin();
	temp++;

	for (int i = numbers.size() - 1; i >= 0; i--)
	{
		if (numbers[i].empty())
			numbers.erase(numbers.begin() + i);
	}
	for (; temp != numbers.end(); it++, temp++)
	{
		if (it->empty())
		{
			// nothing
		}
		else if(!temp->empty() && it->size() == temp->size())
		{
			if (it->back() > temp->back())
			{
				temp->splice(temp->end(), *it);
				std::rotate(it, temp, temp + 1);
			}
			else
				it->splice(it->end(), *temp);
			comparisons++;
		}
	}
}

void PmergeMe::addList(char *nr)
{
	char *end;
	long i = std::strtol(nr, &end, 10);

	std::list<int> list;

	// ERROR  MANAGEMENT
	if (*end != '\0')
	{
		throw std::runtime_error("'" + std::string(nr) + "' is not a valid integer");
	}
	else if (nr[0] == '-')
	{	
		throw std::runtime_error("PmergeMe does not allow for negative numbers");
	}
	else if (i > 2147483647 || static_cast<std::string>(nr).length() > 10)
	{
		throw std::runtime_error("'" + std::string(nr) + "' is too large to be an integer");
	}

	list.push_back(i);

	numbers.push_back(list);
}

std::ostream& operator<<(std::ostream &os, PmergeMe &src)
{
	int i = 0;
	int j = 0;
	std::vector< std::list<int> >::const_iterator it = src.getNumbers().begin();
	for (; it != src.getNumbers().end(); it++)
	{
		j++;
		if (it->empty())
			i++;
		else
		{
			std::list<int>::const_iterator it2 = it->begin();
			for (; it2 != it->end(); it2++)
			{
				os << *it2 << " ";
			}
		}
		std::cout << "|";
	}
	os << std::endl << "comparisons: " << src.getComparisons() << std::endl;
	os << "empty lists: " << i << std::endl;
	os << "lists: " << j << std::endl;
	return os;
}
