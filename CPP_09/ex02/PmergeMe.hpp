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

class PmergeMe
{
	private:
		// CONSTRUCTOR
		PmergeMe();

		// OBJECTS
		std::vector< std::list<int> > numbers;
//		std::vector< std::pair<int, std::list<int> > > main;
//		std::vector< std::pair<int, std::list<int> > > pend;
		int leftover;
		int comparisons;
		
		// FUNCTIONS
		void addList(char *nr);
		void mergeSort();
		void mainPendGen();
	public:
		// CONSTRUCTORS & DESTRUCTOR
		PmergeMe(int ac, char **input);
		PmergeMe(PmergeMe &src);
		~PmergeMe();

		// OPERATOR OVERLOAD
//		PmergeMe operator=(PmergeMe &src); // TODO add function to cpp file

		// getters
		const std::vector< std::list<int> > &getNumbers() const;
		const int &getComparisons() const;
};

std::ostream& operator<<(std::ostream &os, PmergeMe &src);

#endif
