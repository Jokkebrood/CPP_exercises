#pragma once

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

#define INT 0
#define CHAR 1
#define FLOAT 2
#define DOUBLE 3
#define TYPES 4

class ScalerConverter
{
	public:
		// constructors
		ScalerConverter();
		ScalerConverter(ScalerConverter &src);
		ScalerConverter(std::string input);

		//destructor
		~ScalerConverter();
	
		// operator overload functions
//		ScalerConverter operator=(ScalerConverter &src);

	private:
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
		double _double;
		float _float;
		char _char;
		int	type;
};
