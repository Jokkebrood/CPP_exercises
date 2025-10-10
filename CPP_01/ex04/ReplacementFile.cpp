#include "ReplacementFile.hpp"

ReplacementFile::ReplacementFile(std::string fileName)
: _fileName(fileName)
{
	_file.open(fileName.c_str());
	if (!_file)
		std::cerr << "Error: could not open file" << std::endl;
}

ReplacementFile::~ReplacementFile() {}

void ReplacementFile::copyIntoNewFile(std::string toReplace, std::string replacement)
{
	std::string line;
	
	while (std::getline(_file, line))
	{
		std::string replacedLine;
		size_t startCopy = 0;
		size_t pos;
		
		while ((pos = line.find(toReplace, startCopy)) != std::string::npos)
		{
			replacedLine += line.substr(startCopy, pos - startCopy);
			replacedLine += replacement;
			startCopy = pos + toReplace.length();
		}
		replacedLine += line.substr(startCopy);
		_newFile << replacedLine << "\n";
	}
}

void ReplacementFile::makeNewFile()
{
	std::string newFileName = _fileName + ".replace";
	_newFile.open(newFileName.c_str());
	if (!_newFile)
		std::cerr << "Error: could not create .replace file" << std::endl;
	std::string line;
}
