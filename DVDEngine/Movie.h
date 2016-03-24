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
	string _DVD_Title;
	MovieStatus _Status;
	double _Price;
	FourDigitDatePart _Year;
	string _Genre;
	Date _DVD_ReleaseDate;

};

