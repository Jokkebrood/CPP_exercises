#include "Array.hpp"

int main()
{
	Array<int> a;
	Array<int> b(12);
	try
	{
		std::cout << "This sentence should appear before an error message" << std::endl;
		int j;
		j = b[12];
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "This sentence should appear after an error message" << std::endl;
		int j;
		j = b[1];
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
