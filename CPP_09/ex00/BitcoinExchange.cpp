#include "BitcoinExchange.hpp"

FindData::FindData() {}
FindData::~FindData() {}
FindData::FindData(const FindData &src)
{
	*this = src;
} // TODO copy data

bool isNumberRange(const std::string& s, std::size_t x, std::size_t y)
{
	if (x > y || y >= s.length())
		return false;

	for (std::size_t i = x; i <= y; ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

bool isDateSyntaxValid(std::string dataLine)
{
	if (!isNumberRange(dataLine, 0, 3) ||
			!isNumberRange(dataLine, 5, 6) ||
			!isNumberRange(dataLine, 8, 9))
		return false;
	else if (dataLine[4] != '-' || dataLine[7] != '-')
		return false;
	return true;
}

Date dataLineToDate(std::string dataLine)
{
	Date date;
	date.y = atoi(dataLine.substr(0, 4).c_str());
	date.m = atoi(dataLine.substr(5, 2).c_str());
	date.d = atoi(dataLine.substr(8, 2).c_str());
	return date;
}

bool isDateReal(std::string dataLine)
{
	Date date = dataLineToDate(dataLine);
	if (date.y < 1000)
		return false;
	else if (date.d > 31 ||
		(date.d > 30 && (date.m == 4 || date.m == 6 || date.m == 9 || date.m == 11)) ||
		(date.d > 28 && (date.y % 4 != 0) && (date.m == 2)) || 
		(date.d > 29 && (date.y % 4 == 0) && (date.m == 2)))
		return false;
	else
		date.d++;
	return true;
}

int isDateValid(std::string dataLine)
{
	if (isDateSyntaxValid(dataLine) == false)
		return BAD_SYNTAX;
	else if (isDateReal(dataLine) == false)
		return BAD_DATE;
	else
		return VALID;
}

// Return rurrent date as an array of 3 integers (Y-M-D)
Date currentDate()
{
	std::time_t now = std::time(NULL);
	std::tm* local = std::localtime(&now);
	Date today;
	today.y = local->tm_year + 1900;
	today.m = local->tm_mon + 1;
	today.d = local->tm_mday;
	return today;
}

void incrementDate(Date &date)
{
	if (date.d == 31 && date.m == 12)
	{
		date.y++;
		date.m = 1;
		date.d = 1;
	}
	else if (date.d == 31 ||
		(date.d == 30 && (date.m == 4 || date.m == 6 || date.m == 9 || date.m == 11)) ||
		(date.d == 28 && (date.y % 4 != 0) && (date.m == 2)) || 
		(date.d == 29 && (date.y % 4 == 0) && (date.m == 2)))
		{
			date.d = 1;
			date.m++;
		}
	else
		date.d++;
}

std::string itos(int i)
{
	std::ostringstream oss;
	oss << i;
	return oss.str();
}

std::string itosDate(Date date)
{
	std::string dateString;

	dateString = itos(date.y);
	dateString += '-';
	if (date.m < 10)
		dateString += '0';
	dateString += itos(date.m);
	dateString += '-';
	if (date.d < 10)
		dateString += '0';
	dateString += itos(date.d);

	return dateString;
}

// Checks the amount of days between two dates
int dateDiff(Date date, std::string dateToMatch)
{
	int i = 0;
	Date temp = date;
	while (itosDate(temp) != dateToMatch)
	{
		incrementDate(temp);
		i++;
	}
	return i;
}

void FindData::makeDataMap()
{
	std::ifstream data("data.csv");
	std::string dataLine;

	Date date;
	date.y = 2009;
	date.m = 1;
	date.d = 2;

	double bitValue;

	std::string dateString = itosDate(date);
	std::string lastDataLine = dateString;

	getline(data, dataLine);
	while (getline(data, dataLine))
	{
		int diff = dateDiff(date, dataLine.substr(0, 10));
		for (int i = 1; (i % (diff + 1)) != 0; ++i)
		{
			dateString = itosDate(date);
			bitValue = atof(lastDataLine.substr(11, lastDataLine.length() - 11).c_str());
			allData.insert(std::make_pair(dateString, bitValue));
			incrementDate(date);
		}
		lastDataLine = dataLine;
	}
	dateString = itosDate(date);
	bitValue = atof(lastDataLine.substr(11, lastDataLine.length() - 11).c_str());
	allData.insert(std::make_pair(dateString, bitValue));
}
