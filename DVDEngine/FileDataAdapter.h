#pragma once
#include "FileManager.h"
#include "BaseDataModel.h"
#include "Movie.h"
#include <vector>

template<typename  DataItemType=BaseDataModel>
class FileDataAdapter
{
short progressOfReading=0;
short previosProgressOfReading=0;
const FileManager* fileManager;
vector<DataItemType> list;
public:
	explicit FileDataAdapter(void);
	explicit FileDataAdapter(const FileManager* const);
	void Execute(bool);

	vector<DataItemType> getResultSet()
	{
		return this->list;
	}

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
void FileDataAdapter<DataItemType>::Execute(bool showProgress=false)
{
	if(this->fileManager->IsOpen())
	{
		string nextLine;
		system("cls");
		cout << "Loading data please wait..." << endl;
		cout << "% 0 record processed." << endl;
		while (getline(*(fileManager->getFileStream()), nextLine))
		{
			++progressOfReading;
			try
			{
				if (showProgress)
				{
					if (previosProgressOfReading < (progressOfReading / 51))
					{
						system("cls");
						cout << "Loading data please wait..." << endl;
						cout << "% " << (progressOfReading / 52) << " record processed." << endl;
						cout << string(progressOfReading / 70, 254) << endl;
						_sleep(20);
						previosProgressOfReading = progressOfReading / 51;
					}
				}

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
		system("cls");
		cout << "Loading data into memory.Please wait..." << endl;
		cout << "% 100 record processed." << endl;
		cout << string(progressOfReading / 70, 254) << endl;
		_sleep(500);
	}
}

template<typename DataItemType = BaseDataModel>
FileDataAdapter<DataItemType>::~FileDataAdapter()
{
	if (fileManager == nullptr) return;
	delete fileManager;
}