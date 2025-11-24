#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Cat cat;
	const Dog dog;
	Dog doggy = dog;
	Cat catCopy(cat);

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();

	catCopy.makeSound();
	meta->makeSound();
	doggy.makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Added ex01 tests" << std::endl;
	std::cout << std::endl;
	Animal* ex01[20];
	for (int nr = 0; nr < 20; nr++)
	{
		if (nr % 2 == 0)
			ex01[nr] = new Dog;
		else
			ex01[nr] = new Cat;
	}

	for (int nr = 0; nr < 20; nr++)
	{
		std::cout << nr + 1 << ") ";
		ex01[nr]->makeSound();
		std::cout << std::endl;
		delete ex01[nr];
		std::cout << std::endl;
	}
	delete meta;
	delete j;
	delete i;
	return 0;
}
