#pragma once
#include <string>
#include <fstream>

class FileManager
{
std::fstream* fileStream;
public:
	FileManager(const std::string* const fileName, std::ios::open_mode);
	bool IsOpen(void) const;
	void Close(void) const;
	std::fstream* getFileStream(void) const;
	~FileManager();
};

