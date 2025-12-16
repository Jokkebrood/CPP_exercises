#include "ScalerConverter.hpp"

ScalerConverter::ScalerConverter() {}

ScalerConverter::ScalerConverter(ScalerConverter &src)
{
	*this = src;
}

ScalerConverter::ScalerConverter(std::string input) : _input(input)
{
	converter();
}

ScalerConverter::~ScalerConverter() {}

ScalerConverter& ScalerConverter::operator=(ScalerConverter &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

void ScalerConverter::checkType()
{
	int dot = 0;

	type = INT;

	// check for -inf, nanf, etc. exceptions
	if (_input.compare("nan") == 0 || _input.compare("-inf") == 0
		|| _input.compare("+inf") == 0)
	{
		type = DOUBLE_NAN;
		return ;
	}
	if (_input.compare("nanf") == 0 || _input.compare("-inff") == 0 ||
		_input.compare("+inff") == 0)
	{
		type = FLOAT_NAN;
		return ;
	}
	// check for type
	if (_input.length() == 1 && !isdigit(_input[0]))
	{
		type = CHAR;
	}
	else if (!isdigit(_input[0]) && _input[0] != '-' && _input[0] != '+')
	{
		throw std::runtime_error("ERROR: invalid input");
	}
	for (int i = 1; _input[i]; i++)
	{
		if (!isdigit(_input[i]))
		{
			if (_input[i] == '.' && dot == 0)
			{
				dot++;
				type = DOUBLE;
			}
			else if (!_input[i + 1] && _input[i] == 'f')
				type = FLOAT;
			else 
				throw std::runtime_error("ERROR: invalid input");
		}
	}
	if (dot > 1)
		throw std::runtime_error("ERROR: invalid input");
}

void ScalerConverter::convertChar()
{
	_char = _input[0];
	_int = (int)_char;
	_double = (double)_char;
	_float = (float)_char;
}

void ScalerConverter::convertInt()
{
	_int = atoi(_input.c_str());
	_char = (char)_int;
	_double = (double)_int;
	_float = (float)_int;
}

void ScalerConverter::convertFloat()
{
	_double = std::strtod(_input.c_str(), 0);
	_float = static_cast<float>(_double);
	_int = (int)_double;
	_char = (char)_double;
}

void ScalerConverter::convertDouble()
{
	_double = std::strtod(_input.c_str(), 0);
	_float = static_cast<float>(_double);
	_int = (int)_double;
	_char = (char)_double;
}

void ScalerConverter::conversionPrinter()
{
	if (_char <= 31 || _char == 127)
		std::cout << "char: non printable char" << std::endl;
	else if (_char > 127)
		std::cout << "char: no char with this value" << std::endl;
	else
		std::cout << "char: " << _char << std::endl;
	if (type == DOUBLE_NAN || type == FLOAT_NAN)
		std::cout << "int: no int equivalent" << std::endl;
	else	
		std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void ScalerConverter::converter()
{
	checkType();
	void (ScalerConverter::*ptr[TYPES])() =
	{
		&ScalerConverter::convertInt,
		&ScalerConverter::convertChar,
		&ScalerConverter::convertFloat,
		&ScalerConverter::convertDouble,
		&ScalerConverter::convertFloat,
		&ScalerConverter::convertDouble
	};
	(this->*ptr[type])();
	conversionPrinter();
}
