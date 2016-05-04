#pragma once
#ifndef FILEDATAADAPTER_H
#define FILEDATAADAPTER_H
#include "FileManager.h"
#include "BaseDataModel.h"
#include "Movie.h"

template<typename  DataItemType=BaseDataModel>
class FileDataAdapter
{
const FileManager* fileManager;
vector<DataItemType> list;
public:
	explicit FileDataAdapter(void);
	explicit FileDataAdapter(const FileManager* const);
	void Execute(void);
	~FileDataAdapter();
};

template<typename DataItemType = BaseDataModel>
FileDataAdapter<DataItemType>::FileDataAdapter(void) : fileManager(nullptr) {}

template<typename DataItemType = BaseDataModel>
FileDataAdapter<DataItemType>::FileDataAdapter(const FileManager* const releatedFileManager)
{
	if (releatedFileManager == nullptr) return;
	fileManager = releatedFileManager;
}

template <typename DataItemType = BaseDataModel>
void FileDataAdapter<DataItemType>::Execute()
{
	if(this->fileManager->IsOpen())
	{
		string nextLine;
		while (getline(*(fileManager->getFileStream()), nextLine))
		{
			try
			{
			DataItemType* f =new DataItemType(nextLine);
			f->Parse();
			list.push_back(*f);
			}
			catch (exception& e)
			{
				cerr << e.what();
			}
		}
		fileManager->Close();
	}
}

template<typename DataItemType = BaseDataModel>
FileDataAdapter<DataItemType>::~FileDataAdapter()
{
	if (fileManager == nullptr) return;
	delete fileManager;
}

#endif