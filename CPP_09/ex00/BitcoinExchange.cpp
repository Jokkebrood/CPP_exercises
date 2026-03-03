#include "BitcoinExchange.hpp"

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
FindData::FindData() {}

FindData::FindData(const FindData &src)
{
	*this = src;
}

FindData::FindData(std::string input)
{
	makeDataMap();

	std::ifstream inputFile(input.c_str());

	if (!inputFile)
		throw std::invalid_argument("\033[31mInvalid file name\033[0m");

	std::string inputLine;
	while (getline(inputFile, inputLine))
	{
		std::cout << errorCheck(inputLine) << std::endl;
	}
}

FindData::~FindData() {}

std::map<std::string, double> FindData::getAllData() const
{
	return allData;
}

std::string FindData::createOutputLine(std::string inputLine, std::string valDate)
{
	double worth;
	std::map<std::string, double>::iterator it = allData.find(valDate);

	if (atof(inputLine.substr(13, inputLine.length() - 13).c_str()) > 2147483647 ||
			inputLine.substr(13, inputLine.length() - 13).length() > 10)
		return "\033[31mERROR: Bitcoin amount too large -> \033[0m\"" +
			inputLine.substr(13, inputLine.length() - 14) + '"';

	worth = it->second * atof(inputLine.substr(13, inputLine.length() - 13).c_str());
	valDate += " -> " + inputLine.substr(13, inputLine.length() - 13) + " -> " + itos(worth);
	return valDate;
}

std::string FindData::errorCheck(std::string inputLine)
{
	// Every invalid input error
	if (inputLine.length() < 14)
		return "\033[31mERROR: Invalid line syntax -> \033[0m\"" + inputLine + '"';

	else if (!isDateSyntaxValid(inputLine.substr(0, 10)))
		return "\033[31mERROR: Invalid date syntax\033[0m";

	else if (!isDateReal(inputLine.substr(0, 10)))
		return "\033[31mERROR: Invalid date -> \033[0m\"" + inputLine.substr(0, 10) + '"';

	else if (inputLine.substr(10, 3).compare(" | "))
		return "\033[31mERROR: Invalid seperator -> \033[0m\"" + inputLine.substr(10, 3) + '"';

	else if (!isValidDouble(inputLine.substr(13, inputLine.length() - 13)))
		return "\033[31mERROR: Invalid bitcoin amount -> \033[0m\"" +
		inputLine.substr(13, inputLine.length() - 13) + '"';

	else
	{
		std::string outputLine = inputLine.substr(0, 10);

		if (allData.find(outputLine) != allData.end())
			outputLine = createOutputLine(inputLine, outputLine);
		else
		{
			Date date = dataLineToDate(inputLine.substr(0, 10));
			if (date.y < 2009 || (date.y == 2009 && date.m == 1 && date.d == 1))
				outputLine = createOutputLine(inputLine, "2009-01-02");
			else
				outputLine = createOutputLine(inputLine, "2022-03-29");
		}
		return outputLine;
	}
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

// UTILS

// Checks if a range of characters in a string contains anything but numbers
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

// Checks if date syntax is valid
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

// Turns a date string ("YYYY-MM-DD") into 3 integers
Date dataLineToDate(std::string dataLine)
{
	Date date;
	date.y = atoi(dataLine.substr(0, 4).c_str());
	date.m = atoi(dataLine.substr(5, 2).c_str());
	date.d = atoi(dataLine.substr(8, 2).c_str());
	return date;
}

// checks if date is real
bool isDateReal(std::string dataLine)
{
	Date date = dataLineToDate(dataLine);
	if (date.y < 1000 || date.m < 1 || date.m > 12 || date.d < 1)
		return false;
	else if (date.d > 31 ||
		(date.d > 30 && (date.m == 4 || date.m == 6 || date.m == 9 || date.m == 11)) ||
		(date.d > 28 && (date.y % 4 != 0) && (date.m == 2)) || 
		(date.d > 29 && (date.y % 4 == 0) && (date.m == 2)))
		return false;
	return true;
}

// Checks if date syntax is valid and date is real
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

// moves date by one day forward
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


// integers to date ("YYYY-MM-DD") conversion
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

// Check if bitcoin amount in input is valid
bool isValidDouble(const std::string& str)
{
	if (str.empty())
		return false;

	size_t i = 0;
	if (i == str.size())
		return false;

	bool hasDigits = false;
	bool hasDot = false;

	while (i < str.size())
	{
		if (str[i] >= '0' && str[i] <= '9')
			hasDigits = true;
		else if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else
			return false;
		++i;
	}
	return hasDigits;
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
