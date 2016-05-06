#pragma once
#include <string>
#include "MovieStatus.h"
#include "FourDigitDatePart.h"
#include "Date.h"
#include "BaseDataModel.h"
using namespace std;
class Movie:public BaseDataModel
{
public:
	Movie(string,MovieStatus,double,FourDigitDatePart,string, Date);
	explicit Movie(const string&);
	void Parse() override;
	~Movie();
	char getPriceUnitSymbol();
	string getDVD_Title();
	MovieStatus getStatus();
	double getPrice();
	FourDigitDatePart getYear();
	string getGenre();
	Date getDVD_ReleaseDate();
	int getID();

private:
	char PriceUnitSymbol;
	string DVD_Title;
	MovieStatus Status;
	double Price;
	FourDigitDatePart Year;
	string Genre;
	Date DVD_ReleaseDate;
	int ID;

};

