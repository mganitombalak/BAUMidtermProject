#pragma once
#include "FileDataAdapter.h"
#include "ApplicationManager.h"
#include <iostream>
#include "Utility.h"

class DataCollector
{
	FileDataAdapter<Movie>* fda;
	ApplicationManager* appMgr;
public:

	void setAdapter(FileDataAdapter<Movie>* adapter, ApplicationManager* manager);
	void filterByTitle();
	void filterByID();
	void compareByPrice();
	void groupByGenre();
	void groupCountByGenre();
	void calcAvgPrice();
	void filterByPriceGreaterThen();
	void calcAvgPriceByGenre();
	void filterByDateGreaterThen();
	DataCollector();
	~DataCollector();
	
};

