#pragma once
#ifndef FILEDATAADAPTER_H
#define FILEDATAADAPTER_H
#include "FileManager.h"
template<typename DataItemType>
class FileDataAdapter
{
const FileManager* fileManager;
DataItemType* list;
public:
	explicit FileDataAdapter(void);
	explicit FileDataAdapter(const FileManager* const);
	void Execute(void);
	~FileDataAdapter();
};

template<typename DataItemType>
FileDataAdapter<DataItemType>::FileDataAdapter(void) : fileManager(nullptr) {}

template<typename DataItemType>
FileDataAdapter<DataItemType>::FileDataAdapter(const FileManager* const releatedFileManager)
{
	if (releatedFileManager == nullptr) return;
	fileManager = releatedFileManager;
}

template <typename DataItemType>
void FileDataAdapter<DataItemType>::Execute()
{
	if(this->fileManager->IsOpen())
	{
		
	}
}

template<typename DataItemType>
FileDataAdapter<DataItemType>::~FileDataAdapter()
{
	if (fileManager == nullptr) return;
	delete fileManager;
}

#endif