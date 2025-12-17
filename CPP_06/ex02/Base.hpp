#pragma once

#include <iostream>
#include <string>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

std::ostream &operator<<(std::ostream &os, Base const &obj)
{
	if (dynamic_cast<A const*>(&obj))
		os << "A";
	else if (dynamic_cast<B const*>(&obj))
		os << "B";
	else
		os << "C";
	return os;
};
