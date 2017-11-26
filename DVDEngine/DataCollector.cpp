#include "Headers/DataCollector.h"



void DataCollector::setAdapter(FileDataAdapter<Movie>* adapter, ApplicationManager* manager)
{
	fda = adapter;
	appMgr = manager;
}

void DataCollector::filterByTitle()
{
	system("cls");
	cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(26, 176) << " TITLE FILTER " << string(26, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	string title;
	while (!title.empty())
	{
		cout << "Please enter a title to search(type '#' to main menu):" << ends;
		cin >> title;
		if (title[0] == '#')
		{
			appMgr->ShowAndAskForMainMenu();
			return;
		}
		string headers[] = { "ID","Title" };
		Utility::PrintGridHeaders(headers);
		for (Movie m : fda->getResultSet())
		{
			if (m.getDVD_Title().find(title) != string::npos)
			{
				m.Print();
			}
		}
	}

}

void DataCollector::filterByID()
{
}

void DataCollector::compareByPrice()
{
}

void DataCollector::groupByGenre()
{
}

void DataCollector::groupCountByGenre()
{
}

void DataCollector::calcAvgPrice()
{
}

void DataCollector::filterByPriceGreaterThen()
{
}

void DataCollector::calcAvgPriceByGenre()
{
}

void DataCollector::filterByDateGreaterThen()
{
}

DataCollector::DataCollector() :fda(nullptr), appMgr(nullptr)
{
}


DataCollector::~DataCollector()
{
}
