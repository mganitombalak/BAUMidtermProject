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
	void Print() const;
	~Movie();
	char getPriceUnitSymbol() const;
	string getDVD_Title() const;
	MovieStatus getStatus() const;
	double getPrice() const;
	FourDigitDatePart getYear()const;
	string getGenre() const;
	Date getDVD_ReleaseDate() const;
	int getID() const;

private:
	string DVD_Title;
	MovieStatus Status;
	double Price;
	FourDigitDatePart Year;
	string Genre;
	Date DVD_ReleaseDate;
	int ID;
	char PriceUnitSymbol;
};

