#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP
#include <string>
#include <iostream>
#include <ctime> // std::time_t
#include <fstream> // std::ifstream
#include <cctype> // std::isdigit()
#include <cstdlib> // atof()
#include <map>
#include <sstream> // static_cast

#define VALID 0
#define BAD_SYNTAX 1
#define BAD_DATE 2

#define Y 0
#define M 1
#define D 2

struct Date
{
	int y;
	int m;
	int d;
};

class FindData
{
	private:
		// Constructors, destructor, operator overload =
		FindData(const FindData &src);

//		FindData operator=(FindData &src);

		// Objects:
		std::map<std::string, double> result;
	public:
		FindData();
		~FindData();

		// functions
		void makeDataMap();
		void produceResult();
		int checkValidDate(std::string);

		std::map<std::string, double> allData; // TODO move to private and make getter
};

template<typename T>
T min(T a, T b)
{
        if (a < b)
                return a;
        return b;
}

#endif
