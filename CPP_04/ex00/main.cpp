#include "Cat.hpp"
#include "WrongCat.hpp"
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
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();

	std::cout << "Animals announce their name:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongI->getType() << " " << std::endl;

	std::cout << "Animals make their sound:" << std::endl;
	std::cout << "cat: ";
	i->makeSound();
	std::cout << "wrong-cat: ";
	wrongI->makeSound();
	std::cout << "dog: ";
	j->makeSound();

	std::cout << "More sounds:" << std::endl;
	catCopy.makeSound();
	meta->makeSound();
	wrongMeta->makeSound();
	doggy.makeSound();
	delete meta;
	delete j;
	delete i;
	delete wrongI;
	delete wrongMeta;
	return 0;
}
