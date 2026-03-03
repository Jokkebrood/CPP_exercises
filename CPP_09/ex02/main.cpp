#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip> // setprecision()

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

template <typename Container>
void comparisons(PmergeMe<Container> pmerge)
{
	int j = pmerge.getNumbers().size();

	std::cout << "──────────────────────────────────────────────────────────────" << std::endl;
	std::cout << std::endl << "my comparisons:  " << pmerge.getComparisons() << std::endl;
	if (maxComparisons(j) == 0)
		std::cout << "max comparisons: number too large" << std::endl;
	else
		std::cout << "max comparisons: " << maxComparisons(j) << std::endl;;
	std::cout << "number of input: " << j << std::endl;
}

int main(int ac, char **av)
{
	try
	{
		std::clock_t startList = std::clock();
		PmergeMe<std::list<int> > pmergeList(ac, av);
		double elapsedList = (double)(std::clock() - startList) / CLOCKS_PER_SEC * 1000000;

		std::cout << pmergeList << std::endl;

		std::clock_t startDeque = std::clock();
		PmergeMe<std::deque<int> > pmergeDeque(ac, av);
		double elapsedDeque = (double)(std::clock() - startDeque) / CLOCKS_PER_SEC * 1000000;
		
		std::cout << "Time to process a range of " << pmergeList.getNumbers().size() <<
		" elements with std::list : " <<
		std::setprecision(6) << elapsedList / 1000000.0 << " us" << std::endl;
		std::cout << "Time to process a range of " << pmergeDeque.getNumbers().size() <<
		" elements with std::deque : " <<
		std::setprecision(6) << elapsedDeque / 1000000.0 << " us" << std::endl;

		comparisons(pmergeList);
	}
	catch (std::runtime_error &e)
	{
		std::cout << red << "ERROR: " << e.what() << reset << std::endl;
	}
}
