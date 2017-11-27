#include "Headers/Date.h"
#include "Headers/Utility.h"

Date::Date():_Day(1),_Month(1),_Year(1900)
{
}

Date::Date(const string&  newDate)
{
	if(newDate.find(".")!= string::npos)
	{
		vector<string> dateParts;
		Utility::Split(newDate, '.',dateParts);
		if (dateParts.size() > 0)
		{
			_Day = stoi(dateParts[1]);
			_Month = stoi(dateParts[0]);
			_Year = stoi(dateParts[2]);

			if (!this->IsValidDate())
				throw 1;
		}
	}
	else if(newDate.find("/") != string::npos)
	{
		vector<string> dateParts;
		Utility::Split(newDate, '/', dateParts);
		if (dateParts.size() > 0)
		{
			_Day = stoi(dateParts[1]);
			_Month = stoi(dateParts[0]);
			_Year = stoi(dateParts[2]);

			if (!this->IsValidDate())
				throw 1;
		}
	}
	else if (newDate.find("-") != string::npos)
	{
		vector<string> dateParts;
		Utility::Split(newDate, '-', dateParts);
		if (dateParts.size() > 0)
		{
			_Day = stoi(dateParts[1]);
			_Month = stoi(dateParts[0]);
			_Year = stoi(dateParts[2]);

			if (!this->IsValidDate())
				throw 1;
		}
	}
}

Date::Date(const TwoDigitDatePart* const day, const TwoDigitDatePart* const month, const FourDigitDatePart* const year)
{
	_Day = *day;
	_Month = *month;
	_Year = *month;
	if (!this->IsValidDate())
		throw 1;
}

bool Date::IsValidDate() const
{
	return (_Day <= 31 & _Day >= 1) && (_Month <= 12 & _Month >= 1) && (_Year > 0);
}

TwoDigitDatePart Date::getDay() const
{
	return this->_Day;
}

TwoDigitDatePart Date::getMonth() const
{
	return this->_Month;
}

FourDigitDatePart Date::getYear() const
{
	return this->_Year;
}

Date::~Date()
{
}
