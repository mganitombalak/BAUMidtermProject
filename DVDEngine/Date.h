#pragma once
#include <string>
#include "TwoDigitDatePart.h"
#include "FourDigitDatePart.h"
using namespace std;
class Date
{
public:
	Date();
	Date(const string* const);
	Date(const TwoDigitDatePart* const, const TwoDigitDatePart* const, const FourDigitDatePart* const);
	static bool IsValidDate();

	~Date();

private:
	TwoDigitDatePart _Day;
	TwoDigitDatePart _Month;
	FourDigitDatePart _Year;
};

