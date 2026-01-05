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

void identify(Base *p)
{
	//std::cout << "Pointer identify called" << std::endl;
	if (dynamic_cast<A const*>(p))
		std::cout  << "A" << std::endl;

	else if (dynamic_cast<B const*>(p))
		std::cout << "B" <<std::endl;

	else
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	//std::cout << "Reference identify called" << std::endl;
	if (dynamic_cast<A const*>(&p))
		std::cout  << "A" << std::endl;

	else if (dynamic_cast<B const*>(&p))
		std::cout << "B" <<std::endl;

	else
		std::cout << "C" << std::endl;
}

int main()
{
	Base *test = generate();
	identify(*test);
	identify(test);
	delete test;
	return 0;
}
