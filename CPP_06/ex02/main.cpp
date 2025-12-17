#include "Base.hpp"
#include <ctime>

Base* generate()
{
	std::time_t now = std::time(NULL);
	std::tm *t = std::localtime(&now);

	Base *base;

	if (t->tm_sec % 3 == 0)
		base = new A();

	else if (t->tm_sec % 3 == 1)
		base = new B();
	
	else
		base = new C();

	return base;
}

int main()
{
	Base *test = generate();
	std::cout << *test << std::endl;
	delete test;
	return 0;
}
