#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class ReplacementFile
{
	private:
		std::string _fileName;
		std::ifstream _file;
		std::ofstream _newFile;
	public:
		ReplacementFile(std::string fileName);
		~ReplacementFile();
		
		void makeNewFile();
		void copyIntoNewFile(std::string toReplace, std::string replacement);
};
