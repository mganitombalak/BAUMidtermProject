#include "FileManager.h"


FileManager::FileManager(const std::string* const fileName, std::ios::open_mode openingMode)
{
	fileStream = new (std::nothrow) std::fstream(*fileName, openingMode);
}

std::fstream* FileManager::getFileStream() const
{
	return fileStream;
}

FileManager::~FileManager()
{
	if (fileStream == nullptr) return;
	fileStream->close();
	delete fileStream;
}
