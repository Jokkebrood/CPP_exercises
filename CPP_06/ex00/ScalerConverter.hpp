#pragma once

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

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
		// constructors
		ScalerConverter(std::string input);

		//destructor
		~ScalerConverter();

	private:
		// constructors
		ScalerConverter();
		ScalerConverter(ScalerConverter &src);

		// operator overload functions
		ScalerConverter& operator=(ScalerConverter &src);

		// Functions
		void converter();
		void checkType();
		void convertChar();
		void convertInt();
		void convertDouble();
		void convertFloat();

		void conversionPrinter();

		// objects
		std::string _input;
		int _int;
		char _char;
		float _float;
		double _double;
		int type;
};
