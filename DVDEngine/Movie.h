#pragma once
#include <string>
#include "MovieStatus.h"
#include "FourDigitDatePart.h"
#include "Date.h"
#include "BaseDataModel.h"
using namespace std;
class Movie:public BaseDataModel
{
	string dataString;
public:
	Movie();
	Movie(string,MovieStatus,double,FourDigitDatePart,string, Date);
	explicit Movie(const string&);
	~Movie();

private:
	string DVD_Title;
	MovieStatus Status;
	double Price;
	FourDigitDatePart Year;
	string Genre;
	Date DVD_ReleaseDate;

};

