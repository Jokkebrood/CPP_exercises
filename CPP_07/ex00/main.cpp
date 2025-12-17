#include "Whatever.hpp"

int main()
{
	int a = 1;
	int b = 46;

	std::cout << "ORIGINAL INT VALUES" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	::swap(a, b);

	std::cout << "SWAPPED INT VALUES" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	std::string stringA = "I'm string A";
	std::string stringB = "I'm string B";

	std::cout <<
	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << std::endl;
	std::cout << "ORIGINAL STRING VALUES" << std::endl;
	std::cout << "string a = " << stringA << std::endl;
	std::cout << "string b = " << stringB << std::endl;
	std::cout << std::endl;

	::swap(stringA, stringB);

	std::cout << "SWAPPED STRING VALUES" << std::endl;
	std::cout << "string a = " << stringA << std::endl;
	std::cout << "string b = " << stringB << std::endl;
	std::cout << std::endl;	
	
	std::cout <<
	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << std::endl;

	std::cout << "TESTING MIN MAX WITH INT" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "the bigger number is: " << ::max(a, b) << std::endl;
	std::cout << "the smaller number is: " << ::min(a, b) << std::endl;
	std::cout << std::endl;
	
	std::cout <<
	"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << std::endl;
	
	float c = 0.056;
	float d = 0.059;

	std::cout << "TESTING MIN MAX WITH FLOAT" << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "the bigger number is: " << ::max(c, d) << std::endl;
	std::cout << "the smaller number is: " << ::min(c, d) << std::endl;
	std::cout << std::endl;
	return 0;
}
