#include "PmergeMe.hpp"

// CONSTRUCTORS & DESTRUCTORS
template <typename Container>
PmergeMe<Container>::PmergeMe() {}
template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container> &src)
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

template <typename Container>
PmergeMe<Container>::PmergeMe(int ac, char **input) : comparisons(0)
{
	if (ac < 3)
		throw std::runtime_error("Expects at least two strings of input");

	for (int i = 1; input[i]; i++)
		addList(input[i]);

	unsortedList = numbers;
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

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

// GETTERS

template <typename Container>
const std::vector< Container > &PmergeMe<Container>::getUnsortedList() const
{
	return unsortedList;
}

template <typename Container>
const std::vector< Container > &PmergeMe<Container>::getNumbers() const
{
	return numbers;
}

template <typename Container>
const int &PmergeMe<Container>::getComparisons() const
{
	return comparisons;
}

// FUNCTIONS

// Merge sorts
template <typename Container>
void PmergeMe<Container>::mergeSort()
{
	typename std::vector<Container>::iterator it = numbers.begin();
	typename std::vector<Container>::iterator itNext = numbers.begin();
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
				itNext->insert(itNext->end(), it->begin(), it->end());
				it->clear();
				std::rotate(it, itNext, itNext + 1);
			}
			else
			{
				it->insert(it->end(), itNext->begin(), itNext->end());
				itNext->clear();
			}
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

template <typename Container>
void PmergeMe<Container>::addList(char *nr)
{
	Container list;

	list.push_back(errorManagement(nr));

	numbers.push_back(list);
}

//**********************************************************************************************

template <typename Container>
void PmergeMe<Container>::printAll()
{
    std::cout << green << "mainChain: ";
    for (typename std::vector<std::pair<int, Container> >::iterator it = mainChain.begin(); it != mainChain.end(); it++)
    {
        std::cout << "(" << it->first << ") ";
        for (typename Container::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << yellow << "pend: ";
    for (typename std::vector<std::pair<int, Container> >::iterator it = pend.begin(); it != pend.end(); it++)
    {
        std::cout << "(" << it->first << ") ";
        for (typename Container::iterator listIt = it->second.begin(); listIt != it->second.end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << red << "nonParticipating: ";
    for (typename std::vector<Container>::iterator it = nonParticipating.begin(); it != nonParticipating.end(); it++)
    {
        for (typename Container::iterator listIt = it->begin(); listIt != it->end(); listIt++)
            std::cout << *listIt << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;
    std::cout << reset << "──────────────────────────────────────────────────────────────" << std::endl;
}

//**********************************************************************************************

// Adds a single element to either the mainChain or pend vector.
template <typename Container>
void addMainPendElement(int i, int len,
	std::vector< std::pair<int, Container > > &maPe,
	typename std::vector<Container>::iterator &itNum)
{
	typename Container::iterator it = itNum->begin();
	std::advance(it, (len / 2));

	if (i % 2 == 0)
	{
		Container firstHalf(itNum->begin(), it);
		maPe.push_back(std::make_pair(i, firstHalf));
	}
	else
	{
		Container secondHalf(it, itNum->end());
		maPe.push_back(std::make_pair(i, secondHalf));
	}
}

// Creates the mainChain and pend vectors
template <typename Container>
void PmergeMe<Container>::makeMainPend()
{
	typename std::vector<Container>::iterator itNum = numbers.begin();

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
template <typename Container>
void PmergeMe<Container>::pushToNumbers()
{
	typename std::vector<std::pair<int, Container> >::iterator itMain = mainChain.begin();

	for (; itMain != mainChain.end(); itMain++)
		numbers.push_back(itMain->second);

	if (!nonParticipating.empty())
	{
		typename std::vector<Container>::iterator itNon = nonParticipating.begin();

		for (; itNon != nonParticipating.end(); itNon++)
			numbers.push_back(*itNon);
	}
}

template <typename Container>
void PmergeMe<Container>::sortToMain(typename std::vector<std::pair<int, Container> >::iterator itPend)
{
    int low = 0;
    int high = mainChain.size();
	
	typename std::vector<std::pair<int, Container> >::iterator it = mainChain.begin();
	for (int i = 0; it != mainChain.end(); it++, i++)
	{
		if (it->first + 1 == itPend->first)
			high = i + 1;
	}
    while (low < high)
    {
        int mid = (low + high) / 2;
        typename std::vector<std::pair<int, Container> >::iterator itMid = mainChain.begin();
        std::advance(itMid, mid);
        comparisons++;
        if (itMid->second.back() < itPend->second.back())
            low = mid + 1;
        else
            high = mid;
    }

    typename std::vector<std::pair<int, Container> >::iterator insertPos = mainChain.begin();
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
template <typename Container>
void PmergeMe<Container>::recursiveInsertion(int n, typename std::vector<std::pair<int, Container> >::iterator itPend)
{
    int groupSize = jacobthal(n) - jacobthal(n - 1);
    
    typename std::vector<std::pair<int, Container> >::iterator groupEnd = itPend;
    for (int i = 0; i < groupSize && groupEnd != pend.end(); i++)
        groupEnd++;

    typename std::vector<std::pair<int, Container> >::iterator nextGroup = groupEnd;

    typename std::vector<std::pair<int, Container> >::iterator it = groupEnd;
    while (it != itPend)
    {
        --it;
        sortToMain(it);
    }
    if (nextGroup != pend.end())
        recursiveInsertion(n + 1, nextGroup);
}

// all of insertion
template <typename Container>
void PmergeMe<Container>::insertion()
{
	if (!pend.empty())
		recursiveInsertion(2, pend.begin());

	pushToNumbers();

	mainChain.clear();
	pend.clear();
	nonParticipating.clear();
}

// OPERATOR OVERLAOD

template <typename Container>
std::ostream& operator<<(std::ostream &os, PmergeMe<Container> &src)
{
	int j = 0;
	std::cout << red << "unsorted list:" << std::endl;	
	typename std::vector<Container>::const_iterator itUn = src.getUnsortedList().begin();
	for (; itUn != src.getUnsortedList().end(); itUn++)
	{
		for (typename Container::const_iterator listIt = itUn->begin(); listIt != itUn->end(); listIt++)
			std::cout << *listIt << " ";
	}
	std::cout << std::endl << green << "sorted list:";
	typename std::vector<Container>::const_iterator it = src.getNumbers().begin();
	for (int i = 0; it != src.getNumbers().end(); it++, i++, j++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		typename Container::const_iterator it2 = it->begin();
		for (; it2 != it->end(); it2++)
		{
			if (*it2 < 10)
				std::cout << " ";
			os << *it2 << " ";
		}
	}	
	return os;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(PmergeMe<Container> &src)
{
	if (this != &src)
	{
		numbers = src.numbers;
		mainChain = src.mainChain;
		pend = src.pend;
		nonParticipating = src.nonParticipating;
		comparisons = src.comparisons;
	}
	return *this;
}

// EXPLICIT TEMPLATE INSTANTIATION

template class PmergeMe<std::list<int> >;
template class PmergeMe<std::deque<int> >;
template std::ostream& operator<<<std::list<int> >(std::ostream&, PmergeMe<std::list<int> >&);
template std::ostream& operator<<<std::deque<int> >(std::ostream&, PmergeMe<std::deque<int> >&);
