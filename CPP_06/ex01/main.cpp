#include "Serializer.hpp"

int main()
{
	Data data("john", 452108, "15 Poop-street");

	std::cout << "ORIGINAL DATA VALUES" << std::endl;
	std::cout << data << std::endl;
	std::cout << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);

	std::cout << "SERIALIZED PTR VALUE" << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << std::endl;

	Data *copy = Serializer::deserialize(ptr);

	std::cout << "DESERIALIZED PTR VALUE" << std::endl;
	std::cout << *copy << std::endl;

	return 0;
}
