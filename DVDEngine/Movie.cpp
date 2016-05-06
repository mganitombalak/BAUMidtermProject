#include "Movie.h"
#include "Utility.h"
#include <iostream>

ostream& operator<<(ostream& ref,Date x)
{
	
	ref << x.getDay() << "/" << x.getMonth() << "/" << x.getYear() << ends;
	return ref;
}
ostream& operator<<(ostream& ref, MovieStatus x)
{
	switch(x)
	{
	case MovieStatus::Cancelled:
		ref << "Cancelled" << ends;
		break;
	case MovieStatus::Discontinued:
		ref << "Discontinued" << ends;
		break;
	case MovieStatus::Out:
		ref << "Out" << ends;
		break;
	}
	
	return ref;
}

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
		this->Price = stod(result[2].substr(1, result[2].length() - 1));
		this->Year = (result[3].empty()) ? (isdigit(result[3][0]) ? stoi(result[3]) : 0) : 0;
		this->Genre = result[4];
		this->DVD_ReleaseDate = Date(result[5]);
		this->ID = stoi(result[6]);
		this->PriceUnitSymbol = result[2][0];
	}
	catch (exception& e)
	{
		cerr << e.what();
	}
}

void Movie::Print() const
{
	cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << this -> getDVD_Title()
		<< string(1, 186)
		<< this->Status
		<< string(1, 186)
		<<this->Price << this->PriceUnitSymbol
		<< string(1, 186) 
		<< this->Year
		<< string(1, 186)
		<< this->Genre
		<< string(1, 186)
		<< this->DVD_ReleaseDate
		<< this->Genre
		<< string(1, 186)
		<< string(1, 186)
		<< endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
}

Movie::~Movie()
{
}
char Movie::getPriceUnitSymbol() const
{
	return this->PriceUnitSymbol;
};
string Movie::getDVD_Title() const
{
	return this->DVD_Title;
};
MovieStatus Movie::getStatus() const
{
	return this->Status;
};
double Movie::getPrice() const
{
	return this->Price;
};
FourDigitDatePart Movie::getYear() const
{
	return this->Year;
};
string Movie::getGenre() const
{
	return this->Genre;
};
Date Movie::getDVD_ReleaseDate() const
{
	return this->DVD_ReleaseDate;
};
int Movie::getID() const
{
	return this->ID;
};