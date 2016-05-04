#include "Movie.h"



Movie::Movie(string, MovieStatus, double, FourDigitDatePart, string, Date):BaseDataModel(nullptr)
{

}

Movie::Movie(const string& rawData):BaseDataModel(rawData)
{

}

Movie::~Movie()
{
}
