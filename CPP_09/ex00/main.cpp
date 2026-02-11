#include "BitcoinExchange.hpp"

int main( void )
{
	FindData find;
	find.makeDataMap();
	std::map<std::string, double>::const_iterator it;
	for (it = find.allData.begin(); it != find.allData.end(); ++it)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
	return 0;
}
