#include "Movie.h"
#include "Utility.h"


Movie::Movie(string, MovieStatus, double, FourDigitDatePart, string, Date) :BaseDataModel(nullptr)
{

}

Movie::Movie(const string& rawData) : BaseDataModel(rawData)
{

}

void Movie::Parse()
{
	vector<string> result;
	Utility::Split(this->rawData, Utility::Delimeter, result);
	if (result.capacity() <= 0) return;
	this->DVD_Title = result[0];
	this->Status = Utility().MovieStatusParser[result[1]];
	this->Price = stod(result[2].substr(1,result[2].length()-1));
	this->Year = stoi(result[3]);
	this->Genre =result[4];
	this->DVD_ReleaseDate =  Date(result[5]);
	this->ID = stoi(result[6]);
	this->PriceUnitSymbol = result[2][0];

}

Movie::~Movie()
{
}
