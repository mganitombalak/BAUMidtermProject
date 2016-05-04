#pragma once
#include <string>
using namespace std;

class BaseDataModel
{
protected:
	string rawData;
public:
	explicit BaseDataModel(const std::string& RawData);
	~BaseDataModel();
};