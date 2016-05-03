#include "FileDataAdapter.h"


bool FileDataAdapter::IsOpen() const
{
	return fileManager != nullptr?fileManager->getFileStream()->is_open():false;
}

FileDataAdapter::FileDataAdapter(const FileManager* const releatedFileManager)
{
	if (releatedFileManager == nullptr) return;
	fileManager = releatedFileManager;
}

FileDataAdapter::~FileDataAdapter()
{
	if (fileManager == nullptr) return;
	delete fileManager;
}
