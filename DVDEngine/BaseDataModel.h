#pragma once
#include <string>
using namespace std;

class BaseDataModel
{
protected:
	string rawData;
public:
	explicit BaseDataModel(const std::string& RawData);
	virtual void Parse() = 0;
	virtual ~BaseDataModel();
};