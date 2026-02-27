#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept> // throwing errors
#include <cstdlib> //
#include <algorithm> // rotate()

#define red "\x1B[31m"
#define blue "\x1B[34m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define reset "\033[0m"

#define paired 1
#define prevPend -2

class PmergeMe
{
	private:
		//--------------------------------------------------------
		// CONSTRUCTOR
		PmergeMe();

		//--------------------------------------------------------
		// OBJECTS

		// mainChain list
		std::vector< std::list<int> > numbers;

		// initialization and insertion containers
		std::vector< std::pair< int, std::list<int> > > mainChain;
		std::vector< std::pair< int, std::list<int> > > pend;
		std::vector< std::list<int> > nonParticipating;

		// others
		int comparisons;
	
		//--------------------------------------------------------
		// FUNCTIONS
		void addList(char *nr);
		void mergeSort();
		void mainChainPendGen();
		void makeMainPend();
		void insertionStepOne();
		void insertion();
		void printAll(); // TODO remove this
		void recursiveInsertion(int n, int j, std::vector<std::pair< int, std::list<int> > >::iterator itPend);
		void sortToMain(std::vector< std::pair< int, std::list<int> > >::iterator itPend);
		void pushToNumbers();
	public:
		//--------------------------------------------------------
		// CONSTRUCTORS & DESTRUCTOR
		PmergeMe(int ac, char **input);
		PmergeMe(PmergeMe &src);
		~PmergeMe();

		//--------------------------------------------------------
		// OPERATOR OVERLOAD
//		PmergeMe operator=(PmergeMe &src); // TODO add function to cpp file

		//--------------------------------------------------------
		// GETTERS
		const std::vector< std::list<int> > &getNumbers() const;
		const int &getComparisons() const;
};

std::ostream& operator<<(std::ostream &os, PmergeMe &src);

#endif
