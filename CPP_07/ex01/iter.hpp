#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

template<typename T_function, typename T_array>
void iter(T_array *array, int length, T_function function)
{
	for (int i = 0; i < length; i++)
	{
		function(array[i]);
	}
}
