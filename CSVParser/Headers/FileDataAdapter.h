#pragma once
#include "FileManager.h"
#include "BaseDataModel.h"
#include "Movie.h"
#include <vector>
#include <zconf.h>
#include <iostream>

template<typename  DataItemType=BaseDataModel>
class FileDataAdapter
{
short progressOfReading=0;
const FileManager* fileManager;
vector<DataItemType> list;
public:
	explicit FileDataAdapter(void);
	explicit FileDataAdapter(const FileManager* const);
	void Execute(bool=false);

	vector<DataItemType> getResultSet()
	{
		return this->list;
	}

	~FileDataAdapter();
};



template<class DataItemType >
FileDataAdapter<DataItemType>::FileDataAdapter(void) : fileManager(nullptr) {}

template<class DataItemType>
FileDataAdapter<DataItemType>::FileDataAdapter(const FileManager* const relatedFileManager)
{
	if (relatedFileManager == nullptr) return;
	fileManager = relatedFileManager;
}

template <class DataItemType>
void FileDataAdapter<DataItemType>::Execute(bool showProgress)
{
	if(this->fileManager->IsOpen())
	{
        string nextLine;
		system("clear");
		cout << "Loading data please wait..." << endl;
		cout << "% 0 record processed." << endl;
		while (getline(*(fileManager->getFileStream()), nextLine))
		{
			try
			{
				if (showProgress) {

                    system("clear");
                    cout << "Loading data please wait..." << endl;
                    cout << (progressOfReading) << " record processed." << endl;
                }
				DataItemType* f =new DataItemType(nextLine);
				f->Parse();
				list.push_back(*f);
                ++progressOfReading;
			}
			catch (exception& e)
			{
				cerr << e.what();
			}
		}
		fileManager->Close();
		system("clear");
		cout << "Loading data into memory.Please wait..." << endl;
		cout <<progressOfReading <<" record processed." << endl;
	}
}

template<typename DataItemType>
FileDataAdapter<DataItemType>::~FileDataAdapter()
{
	if (fileManager == nullptr) return;
	delete fileManager;
}