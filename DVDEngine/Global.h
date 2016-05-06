#pragma once
#include "Movie.h"
#include "FileDataAdapter.h"
#include "ApplicationManager.h"
static ApplicationManager* appMgr;
static FileDataAdapter<Movie>* fda;
void filterByTitle();
void filterByID();
void compareByPrice();
void groupByGenre();
void groupCountByGenre();
void calcAvgPrice();
void filterByPriceGreaterThen();
void calcAvgPriceByGenre();
void filterByDateGreaterThen();
