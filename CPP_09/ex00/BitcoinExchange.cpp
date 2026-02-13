#include "BitcoinExchange.hpp"

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
		std::cout << createOutputLine(inputLine) << std::endl;
	}
}

FindData::~FindData() {}

std::map<std::string, double> FindData::getAllData() const
{
	return allData;
}



std::string FindData::createOutputLine(std::string inputLine)
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
		double worth;
		std::string outputLine = inputLine.substr(0, 10);

		if (allData.find(outputLine) != allData.end())
		{
			std::map<std::string, double>::iterator it = allData.find(outputLine);

			if (atof(inputLine.substr(13, inputLine.length() - 13).c_str()) > 2147483647 ||
					inputLine.substr(13, inputLine.length() - 13).length() > 10)
				return "\033[31mERROR: Bitcoin amount too large -> \033[0m\"" +
					inputLine.substr(13, inputLine.length() - 14) + '"';

			worth = it->second * atof(inputLine.substr(13, inputLine.length() - 13).c_str());
			outputLine += " -> " + inputLine.substr(13, inputLine.length() - 13) + " -> " + itos(worth);
		}
		else
		{	
			Date date = dataLineToDate(inputLine.substr(0, 10));
			if (date.y < 2009 || (date.y == 2009 && date.m == 1 && date.d == 1))
			{
				std::map<std::string, double>::iterator it = allData.find("2009-01-02");

				if (atof(inputLine.substr(13, inputLine.length() - 13).c_str()) > 2147483647 ||
						inputLine.substr(13, inputLine.length() - 13).length() > 10)
				return "\033[31mERROR: Bitcoin amount too large -> \033[0m\"" +
				inputLine.substr(13, inputLine.length() - 14) + '"';

				worth = it->second * atof(inputLine.substr(13, inputLine.length() - 13).c_str());
				outputLine += " -> " + inputLine.substr(13, inputLine.length() - 13) + " -> " + itos(worth);
			}
			else
			{
				std::map<std::string, double>::iterator it = allData.find("2022-03-29");

				if (atof(inputLine.substr(13, inputLine.length() - 13).c_str()) > 2147483647 ||
						inputLine.substr(13, inputLine.length() - 13).length() > 10)
				return "\033[31mERROR: Bitcoin amount too large -> \033[0m\"" +
				inputLine.substr(13, inputLine.length() - 14) + '"';

				worth = it->second * atof(inputLine.substr(13, inputLine.length() - 13).c_str());
				outputLine += " -> " + inputLine.substr(13, inputLine.length() - 13) + " -> " + itos(worth);
			}
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
