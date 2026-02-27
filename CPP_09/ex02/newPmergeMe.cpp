#include "newPmergeMe.hpp"

// CONSTRUCTORS & DESTRUCTORS
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &src)
{
	*this = src;
}

// Checks the largest power of 2 that fits inside size
// e.g. for 61 it would be 32, for 64 it would be 64, for 100 ti would be 64, etc.
unsigned long power2fit(unsigned long size)
{
	unsigned long i = 1;
	while (i <= size)
		i *= 2;
	if (i != 1)
		i /= 2;
	return i;
}

PmergeMe::PmergeMe(int ac, char **input) : comparisons(0)
{
	if (ac < 3)
		throw std::runtime_error("Expects at least two strings of input");

	for (int i = 1; input[i]; i++)
		addList(input[i]);

	unsigned long maxSize = power2fit(numbers.size());
	while (numbers.begin()->size() != maxSize)
		mergeSort();

	while (numbers.begin()->size() != 1)
	{
		makeMainPend();
		insertion();
	}
}

PmergeMe::~PmergeMe() {}

// GETTERS

const std::vector< std::list<int> > &PmergeMe::getNumbers() const
{
	return numbers;
}

const int &PmergeMe::getComparisons() const
{
	return comparisons;
}

// FUNCTIONS

// Merge sorts
void PmergeMe::mergeSort()
{
	std::vector< std::list<int> >::iterator it = numbers.begin();
	std::vector< std::list<int> >::iterator itNext = numbers.begin();
	itNext++;

	for (; itNext != numbers.end(); itNext++, it++)
	{
		if (it->empty())
			; // nothing
		else if(!itNext->empty() && it->size() == itNext->size())
		{
			comparisons++;
			if (it->back() > itNext->back())
			{
				itNext->splice(itNext->end(), *it);
				std::rotate(it, itNext, itNext + 1);
			}
			else
				it->splice(it->end(), *itNext);
		}
	}

	for (int i = numbers.size() - 1; i >= 0; i--)
	{
		if (numbers[i].empty())
			numbers.erase(numbers.begin() + i);
	}
}

// Throws error if nr is not convertable to an int
// else returns int conversion of nr
int errorManagement(char *nr)
{
	char *end;
	long i = std::strtol(nr, &end, 10);

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
	return i;
}

void PmergeMe::addList(char *nr)
{
	std::list<int> list;

	list.push_back(errorManagement(nr));

	numbers.push_back(list);
}

//**********************************************************************************************
void PmergeMe::printAll()
{
    std::cout << "mainChain: ";
    for (std::vector< std::pair<int, std::list<int> > >::iterator it = mainChain.begin(); it != mainChain.end(); it++)
    {
        std::cout << "(" << it->first << ") ";
        for (std::list<int>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << "pend: ";
    for (std::vector< std::pair<int, std::list<int> > >::iterator it = pend.begin(); it != pend.end(); it++)
    {
        std::cout << "(" << it->first << ") ";
        for (std::list<int>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << "nonParticipating: ";
    for (std::vector< std::list<int> >::iterator it = nonParticipating.begin(); it != nonParticipating.end(); it++)
    {
        for (std::list<int>::iterator listIt = it->begin(); listIt != it->end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}
//**********************************************************************************************

// Adds a single element to either the mainChain or pend vector.
void addMainPendElement(int i, int len,
	std::vector< std::pair<int, std::list<int> > > &maPe,
	std::vector< std::list<int> >::iterator &itNum)
{
	std::list<int>::iterator it = itNum->begin();
	std::advance(it, (len / 2));

	if (i % 2 == 0)
	{
		std::list<int> firstHalf(itNum->begin(), it);
		maPe.push_back(std::make_pair(i, firstHalf));
	}
	else
	{
		std::list<int> secondHalf(it, itNum->end());
		maPe.push_back(std::make_pair(i, secondHalf));
	}
}

// Creates the mainChain and pend vectors
void PmergeMe::makeMainPend()
{
	std::vector< std::list<int> >::iterator itNum = numbers.begin();

	unsigned long len = itNum->size();
	int i = 0;

	// mainChain pend loop
	for (; itNum != numbers.end() && itNum->size() == len; i++)
	{
		if (i % 2 == 1 || i == 0)
			addMainPendElement(i, len, mainChain, itNum);
		else
			addMainPendElement(i, len, pend, itNum);

		if (i % 2 == 1)
			itNum++;
	}
	
	// adds non paired element if size matches
	if (itNum != numbers.end() && itNum->size() * 2 == len)
	{
		if (i % 2 == 1 || i == 0)
			mainChain.push_back(std::make_pair(i, *itNum));
		else
			pend.push_back(std::make_pair(i, *itNum));
		itNum++;
	}

	// create nonParticipating vector
	if (itNum != numbers.end())
	{
		for (;itNum != numbers.end(); itNum++, i++)
		{
			nonParticipating.push_back(*itNum);
		}
	}

	for (int i = nonParticipating.size() - 1; i >= 0; i--)
	{
		if (nonParticipating[i].empty())
			nonParticipating.erase(nonParticipating.begin() + i);
	}

	numbers.clear();
	printAll(); // TODO remove this line
}

// copies sorted mainChain and nonParticipating (if not empty) to numbers
void PmergeMe::pushToNumbers()
{
	std::vector<std::pair<int, std::list<int> > >::iterator itMain = mainChain.begin();

	for (; itMain != mainChain.end(); itMain++)
		numbers.push_back(itMain->second);

	if (!nonParticipating.empty())
	{
		std::vector<std::list<int> >::iterator itNon = nonParticipating.begin();

		for (; itNon != nonParticipating.end(); itNon++)
			numbers.push_back(*itNon);
	}
}

void PmergeMe::sortToMain(std::vector<std::pair< int, std::list<int> > >::iterator itPend)
{
    int low = 0;
    int high = mainChain.size();
	
	int whatToCheck = paired;
	unsigned long n = 2;
	for (int i = 1; pend[i - 1].first <= itPend->first && i - 1 < (int)pend.size(); i = n - i, n *= 2)
	{
		if (pend[i - 1].first == itPend->first)
		{
			whatToCheck = prevPend;
			break;
		}
	}

	std::vector<std::pair<int, std::list<int> > >::iterator it = mainChain.begin();
	for (int i = 0; it != mainChain.end(); it++, i++)
	{
		if (it->first + whatToCheck == itPend->first)
		{
			high = i;
			std::cout << green << "pair int val: " << itPend->first << reset << std::endl;
			std::cout << green << "high: " << high << reset << std::endl;
		}
	}
    while (low < high)
    {
        int mid = (low + high) / 2;
        std::vector<std::pair<int, std::list<int> > >::iterator itMid = mainChain.begin();
        std::advance(itMid, mid);
        comparisons++;
        if (itMid->second.back() < itPend->second.back())
            low = mid + 1;
        else
            high = mid;
    }

    std::vector<std::pair< int, std::list<int> > >::iterator insertPos = mainChain.begin();
    std::advance(insertPos, low);
    mainChain.insert(insertPos, *itPend);
}

// inserts all members of pend to mainChain in the appropriate order
void PmergeMe::recursiveInsertion(int n, int j, std::vector<std::pair< int, std::list<int> > >::iterator itPend)
{
    int groupSize = n - j;
    
    std::vector<std::pair<int, std::list<int> > >::iterator groupEnd = itPend;
    for (int i = 0; i < groupSize && groupEnd != pend.end(); i++)
        groupEnd++;

    std::vector<std::pair<int, std::list<int> > >::iterator nextGroup = groupEnd;

    std::vector<std::pair<int, std::list<int> > >::iterator it = groupEnd;
    while (it != itPend)
    {
        --it;
        sortToMain(it);
    }

    if (nextGroup != pend.end())
        recursiveInsertion(n * 2, n, nextGroup);
}

// all of insertion
void PmergeMe::insertion()
{
	if (!pend.empty())
		recursiveInsertion(2, 1, pend.begin());

	pushToNumbers();

	mainChain.clear();
	pend.clear();
	nonParticipating.clear();
}

// OPERATOR OVERLAOD

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
