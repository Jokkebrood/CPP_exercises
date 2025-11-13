#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Cat cat;
	const Dog dog;
//	Dog doggy = dog;
	Cat catCopy(cat);

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();

	catCopy.makeSound();
	meta->makeSound();
//	doggy.makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}
