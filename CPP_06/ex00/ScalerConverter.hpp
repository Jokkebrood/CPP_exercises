#pragma once

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cmath>

#define INT 0
#define CHAR 1
#define FLOAT 2
#define DOUBLE 3
#define DOUBLE_NAN 4
#define FLOAT_NAN 5
#define TYPES 6

class ScalerConverter
{
	public:
		static void converter(std::string);
		
	private:
		// constructors
		ScalerConverter();
		ScalerConverter(ScalerConverter &src);

		//destructor
		~ScalerConverter();

		// operator overload functions
		ScalerConverter& operator=(ScalerConverter &src);
};
