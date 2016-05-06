#include "Movie.h"
#include "Utility.h"
#include <iostream>


Movie::Movie(string, MovieStatus, double, FourDigitDatePart, string, Date) :BaseDataModel(nullptr)
{

}

Movie::Movie(const string& rawData) : BaseDataModel(rawData)
{
}

void Movie::Parse()
{
	try
	{
	
	vector<string> result;
	Utility::Split(this->rawData, Utility::Delimeter, result);
	if (result.capacity() <= 0) return;
	this->DVD_Title = result[0];
	this->Status = Utility().MovieStatusParser[result[1]];
	this->Price = stod(result[2].substr(1,result[2].length()-1));
	this->Year = (result[3].empty())?(isdigit(result[3][0])?stoi(result[3]):0):0;
	this->Genre =result[4];
	this->DVD_ReleaseDate =  Date(result[5]);
	this->ID = stoi(result[6]);
	this->PriceUnitSymbol = result[2][0];
	}
	catch (exception& e)
	{
		cerr << e.what();
	}
}

Movie::~Movie()
{
}
char Movie::getPriceUnitSymbol() { return this->PriceUnitSymbol; };
string Movie::getDVD_Title() { return this->DVD_Title; };
MovieStatus Movie::getStatus() { return this->Status; };
double Movie::getPrice() { return this->Price; };
FourDigitDatePart Movie::getYear() { return this->Year; };
string Movie::getGenre() { return this->Genre; };
Date Movie::getDVD_ReleaseDate() { return this->DVD_ReleaseDate; };
int Movie::getID() { return this->ID; };