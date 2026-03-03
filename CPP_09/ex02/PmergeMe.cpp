#include "PmergeMe.hpp"

// CONSTRUCTORS & DESTRUCTORS
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &src)
{
	*this = src;
}

// Checks the largest power of 2 that fits inside size
// e.g. for 61 it would be 32, for 64 it would be 64, for 100 it would be 64, etc.
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

	std::cout << red << "unsorted list:" << std::endl;	
	std::vector<std::list<int> >::iterator it = numbers.begin();
	for (; it != numbers.end(); it++)
	{
		for (std::list<int>::iterator listIt = it->begin(); listIt != it->end(); listIt++)
			std::cout << *listIt << " ";
	}
	std::cout << reset << std::endl;

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
    std::cout << green << "mainChain: ";
    for (std::vector< std::pair<int, std::list<int> > >::iterator it = mainChain.begin(); it != mainChain.end(); it++)
    {
        std::cout << "(" << it->first << ") ";
        for (std::list<int>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << yellow << "pend: ";
    for (std::vector< std::pair<int, std::list<int> > >::iterator it = pend.begin(); it != pend.end(); it++)
    {
        std::cout << "(" << it->first << ") ";
        for (std::list<int>::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << red << "nonParticipating: ";
    for (std::vector< std::list<int> >::iterator it = nonParticipating.begin(); it != nonParticipating.end(); it++)
    {
        for (std::list<int>::iterator listIt = it->begin(); listIt != it->end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;
    std::cout << reset << "──────────────────────────────────────────────────────────────" << std::endl;
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
//	printAll(); // TODO remove this line
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
	
	std::vector<std::pair<int, std::list<int> > >::iterator it = mainChain.begin();
	for (int i = 0; it != mainChain.end(); it++, i++)
	{
		if (it->first + 1 == itPend->first)
			high = i + 1;
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

int jacobthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobthal(n - 1) + 2 * jacobthal(n - 2);
}

// inserts all members of pend to mainChain in the appropriate order
void PmergeMe::recursiveInsertion(int n, std::vector<std::pair< int, std::list<int> > >::iterator itPend)
{
    int groupSize = jacobthal(n) - jacobthal(n - 1);
    
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
        recursiveInsertion(n + 1, nextGroup);
}

// all of insertion
void PmergeMe::insertion()
{
	if (!pend.empty())
		recursiveInsertion(2, pend.begin());

	pushToNumbers();

	mainChain.clear();
	pend.clear();
	nonParticipating.clear();
}

// OPERATOR OVERLAOD

int maxComparisons(int n)
{
    int i[56] = {0, 1, 3, 5, 7, 10, 13, 16, 19, 22, 26, 30, 34,
				38, 42, 46, 50, 54, 58, 62, 66, 71, 76, 81, 86,
				91, 96, 101, 106, 111, 116, 121, 126, 131, 136,
				141, 146, 151, 156, 161, 166, 171, 177, 183, 189,
				195, 201, 207, 213, 219, 225, 231, 237, 243, 249, 255};
	if (i[n - 1])
		return i[n - 1];
	else 
		return 0;
}

std::ostream& operator<<(std::ostream &os, PmergeMe &src)
{
	int j = 0;
	std::cout << green << "sorted list:";
	std::vector< std::list<int> >::const_iterator it = src.getNumbers().begin();
	for (int i = 0; it != src.getNumbers().end(); it++, i++, j++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		std::list<int>::const_iterator it2 = it->begin();
		for (; it2 != it->end(); it2++)
		{
			if (*it2 < 10)
				std::cout << " ";
			os << *it2 << " ";
		}
	}	
	std::cout << std::endl 
	<< reset << "──────────────────────────────────────────────────────────────" << std::endl;
	os << std::endl << "my comparisons:  " << src.getComparisons() << std::endl;
	if (&maxComparisons == 0)
		os << "max comparisons: number too large" << std::endl;
	else
		os << "max comparisons: " << maxComparisons(j) << std::endl;;
	os << "number of input: " << j << std::endl;
	return os;
}
