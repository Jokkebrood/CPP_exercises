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

#define red "\x1B[31m"
#define blue "\x1B[34m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define reset "\033[0m"

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
		FindData();
		FindData(const FindData &src);

//		FindData operator=(FindData &src);

		// Objects:
		std::map<std::string, double> result;
		std::map<std::string, double> allData;
	public:
		FindData(std::string input);
		~FindData();

		// getters
		std::map<std::string, double> getAllData() const;

		// functions
		void makeDataMap();
		std::string createOutputLine(std::string inputLine, std::string valDate);
		std::string errorCheck(std::string inputLine);
};

template<typename T>
T min(T a, T b)
{
        if (a < b)
                return a;
        return b;
}

template<typename T>
std::string itos(T i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

bool isNumberRange(const std::string& s, std::size_t x, std::size_t y);
bool isDateSyntaxValid(std::string dataLine);
Date dataLineToDate(std::string dataLine);
bool isDateReal(std::string dataLine);
int isDateValid(std::string dataLine);
Date currentDate();
void incrementDate(Date &date);
std::string itosDate(Date date);
int dateDiff(Date date, std::string dateToMatch);
bool isValidDouble(const std::string& str);

#endif
