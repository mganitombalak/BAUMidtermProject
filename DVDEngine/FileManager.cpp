#include "Headers/FileManager.h"


FileManager::FileManager(const std::string* const fileName, std::ios::open_mode openingMode)
{
	fileStream = new std::fstream(*fileName, openingMode);
}

std::fstream* FileManager::getFileStream() const
{
	return fileStream;
}
bool FileManager::IsOpen() const
{
	return fileStream != nullptr?fileStream->is_open():false;
}

void FileManager::Close() const
{
	fileStream->close();
}

FileManager::~FileManager()
{
	if (fileStream == nullptr) return;
	fileStream->close();
	delete fileStream;
}
