#pragma once
#include <string>
#include "MovieStatus.h"
#include "FourDigitDatePart.h"
#include "Date.h"
using namespace std;
class Movie
{
public:
	Movie();
	Movie(string,MovieStatus,double,FourDigitDatePart,string, Date);
	~Movie();

private:
	string DVD_Title;
	MovieStatus Status;
	double Price;
	FourDigitDatePart Year;
	string Genre;
	Date DVD_ReleaseDate;

};

