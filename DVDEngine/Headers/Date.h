#pragma once
#include <string>
#include "TwoDigitDatePart.h"
#include "FourDigitDatePart.h"
using namespace std;
class Date
{
public:
	Date();
	explicit Date(const string&);
	Date(const TwoDigitDatePart* const, const TwoDigitDatePart* const, const FourDigitDatePart* const);
	bool IsValidDate() const;
	TwoDigitDatePart getDay(void) const;
	TwoDigitDatePart getMonth(void) const;
	FourDigitDatePart getYear(void) const;
	~Date();

private:
	TwoDigitDatePart _Day;
	TwoDigitDatePart _Month;
	FourDigitDatePart _Year;
};

