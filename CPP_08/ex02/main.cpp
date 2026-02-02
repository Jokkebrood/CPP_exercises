#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << yellow << "MY TESTS" << reset << std::endl;
	std::cout << green << "Tests for iterator begin & end" << reset << std::endl;

	MutantStack<int> mystack;
	for (int i = 5; i <= 50; i += 5)
	{
		mystack.push(i);
	}

	MutantStack<int>::iterator iter_b = mystack.begin();
	MutantStack<int>::iterator iter_e = mystack.end();

	while (iter_e != iter_b)
	{
		iter_e--;
		std::cout << *iter_e << " ";
	}
	std::cout << std::endl;


	std::cout << green << "Tests for const iterator begin & end" << reset << std::endl;

	MutantStack<int>::const_iterator const_iter_b = mystack.begin();
	MutantStack<int>::const_iterator const_iter_e = mystack.end();

	while (const_iter_e != const_iter_b)
	{
		const_iter_e--;
		std::cout << *const_iter_e << " ";
	}
	std::cout << std::endl;

	std::cout << green << "Tests for reverse iterator begin & end" << reset << std::endl;

	MutantStack<int>::reverse_iterator riter_b = mystack.rbegin();
	MutantStack<int>::reverse_iterator riter_e = mystack.rend();

	while (riter_e != riter_b)
	{
		riter_e--;
		std::cout << *riter_e << " ";
	}
	std::cout << std::endl;


	std::cout << green << "Tests for const reverse iterator begin & end" << reset << std::endl;

	MutantStack<int>::const_reverse_iterator const_riter_b = mystack.rbegin();
	MutantStack<int>::const_reverse_iterator const_riter_e = mystack.rend();

	while (const_riter_e != const_riter_b)
	{
		const_riter_e--;
		std::cout << *const_riter_e << " ";
	}
	std::cout << std::endl;
	return 0;
}
