#pragma once

#include <strings>
#include <iostream>

class ScalerConverter
{
	private:
		// constructors
		ScalerConverter();
		ScalerConverter(ScalerConverter &src);
		ScalerConverter(std::string input);

		//destructor
		~ScalerConverter();
	
		// operator overload functions
		ScalerConverter operator=(ScalerConverter &src);

		// objects
		int _int;
		char _char;
		float _float;
		double _double;
}
