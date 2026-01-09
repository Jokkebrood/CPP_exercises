#include "easyfind.hpp"
#include <iostream>

int main()
{
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		std::vector<int>::iterator test = easyfind<std::vector<int> >(v, 5);
		std::cout << "Value: " << *test << " was found in container" << std::endl;
		test = easyfind<std::vector<int> >(v, 15);
		std::cout << "Value: " << *test << " was found in container" << std::endl;
	}
	catch (int i)
	{
		std::cout << "number not found in list" << std::endl;
	}
	return 0;
}
