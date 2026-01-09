#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& v, int nr)
{
	typename T::iterator it = find(v.begin(), v.end(), nr);
	if (it == v.end())
		throw 1;
	return it;
}

#endif
