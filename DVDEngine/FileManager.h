#pragma once
#include <string>
#include <fstream>

class FileManager
{
std::fstream* fileStream;
public:
	FileManager(const std::string* const fileName, std::ios::open_mode);
	std::fstream* getFileStream() const;
	~FileManager();
};

