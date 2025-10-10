#pragma once

#include <iostream>
#include <string>
#include <fstream>

class replacementFile
{
	private:
		std::string _fileName;
		std::ifstream _file();
		std::ofstream _newFile();
	public:
		replacementFile(std::string fileName, std::string fileName);
		~replacementFile();
		
		void makeNewFile();
		void fillNewFile();
};
