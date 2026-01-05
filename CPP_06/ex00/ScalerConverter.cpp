#include "ScalerConverter.hpp"

struct Vars {
    long i;
    char c;
    float f;
    double d;
    int type;
};

ScalerConverter::ScalerConverter()
{
	std::cout << "ScalerConverer default constructor" << std::endl;
}

ScalerConverter::ScalerConverter(ScalerConverter &src)
{
	std::cout << "ScalerConvertor copy constructor" << std::endl;
	*this = src;
}

ScalerConverter::~ScalerConverter()
{
	std::cout << "ScalerConvertor destructor" << std::endl;
}

ScalerConverter& ScalerConverter::operator=(ScalerConverter &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

int checkType(std::string _input)
{
	int dot = 0;
	int type = INT;

	// check for -inf, nanf, etc. exceptions
	if (_input.compare("nan") == 0 || _input.compare("-inf") == 0
		|| _input.compare("+inf") == 0)
	{
		return DOUBLE_NAN;
	}
	if (_input.compare("nanf") == 0 || _input.compare("-inff") == 0 ||
		_input.compare("+inff") == 0)
	{
		return FLOAT_NAN;
	}
	// check for vars.type
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
	return type;
}

void convertChar(std::string _input, Vars *vars)
{
	vars->c = _input[0];
	vars->i = (long)vars->c;
	vars->d = (double)vars->c;
	vars->f = (float)vars->c;
}

void convertInt(std::string _input, Vars *vars)
{
	vars->i = atol(_input.c_str());
	vars->c = (char)vars->i;
	vars->d = (double)vars->i;
	vars->f = (float)vars->i;
}

void convertFloat(std::string _input, Vars *vars)
{
	vars->d = std::strtod(_input.c_str(), 0);
	vars->f = static_cast<float>(vars->d);
	vars->i = (long)vars->d;
	vars->c = (char)vars->d;
}

void convertDouble(std::string _input, Vars *vars)
{
	vars->d = std::strtod(_input.c_str(), 0);
	vars->f = static_cast<float>(vars->d);
	vars->i = (long)vars->d;
	vars->c = (char)vars->d;
}

void conversionPrinter(Vars vars)
{
	if (vars.i <= 31 || (vars.i >= 127 && vars.i <= 255))
		std::cout << "char: non printable char" << std::endl;
	else if (vars.i > 255)
		std::cout << "char: no char with this value" << std::endl;
	else
		std::cout << "char: " << vars.c << std::endl;


	if (vars.type == DOUBLE_NAN || vars.type == FLOAT_NAN)
		std::cout << "int: no int equivalent" << std::endl;
	else if (vars.i > 2147483647 || vars.i < -2147483648)
		std::cout << "int: overflow value" << std::endl;
	else
		std::cout << "int: " << vars.i << std::endl;


	if (vars.f != std::floor(vars.f)
		|| (vars.type == FLOAT_NAN || vars.type == DOUBLE_NAN))
		std::cout << "float: " << vars.f << "f" << std::endl;
	else


		std::cout << "float: " << vars.f << ".0f" << std::endl;
	if (vars.d != std::floor(vars.d)
		|| (vars.type == FLOAT_NAN || vars.type == DOUBLE_NAN))
		std::cout << "double: " << vars.d << std::endl;
	else
		std::cout << "double: " << vars.d << ".0" << std::endl;
}

void ScalerConverter::converter(std::string _input)
{
	Vars vars;
	
	vars.type = checkType(_input);
	void (*ptr[TYPES])(std::string, Vars*) =
	{
		&convertInt,
		&convertChar,
		&convertFloat,
		&convertDouble,
		&convertFloat,
		&convertDouble
	};
	(*ptr[vars.type])(_input, &vars);
	conversionPrinter(vars);
}
