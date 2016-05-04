#include "Date.h"

Date::Date():_Day(1),_Month(1),_Year(1900)
{
}

Date::Date(const string&  newDate)
{
	if(newDate.find(".")!= string::npos || newDate.find("/") != string::npos)
	{
		string temp;
		for(int i =0;i<newDate.length();i++)
		{
			if(isdigit(newDate[i]))
			{
				temp.append(&newDate[i]);
			}
			else if (i < 3) {
				_Day = stoi(temp);
				temp = "";
			}
			else if (i > 3 & i < 5){
				_Month = stoi(temp);
				temp = "";
			}
			else
				_Year = stoi(newDate.substr(6, 4));

		}
	}
}

Date::Date(const TwoDigitDatePart* const day, const TwoDigitDatePart* const month, const FourDigitDatePart* const year)
{
	_Day = *day;
	_Month = *month;
	_Year = *month;
	if (!this->IsValidDate())
		throw exception("Invalid date");
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
