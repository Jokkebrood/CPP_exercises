#include "Array.hpp"

int main()
{
	Array<int> a;
	Array<int> b(12);
	try
	{
		int j;
		j = b[13];
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		int j;
		j = b[1];
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
