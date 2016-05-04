#pragma once
#include <string>
#include <vector>
#include <map>
#include "MovieStatus.h"

class Utility
{
public:
	const static char Delimeter='\t';
	std::map<std::string, MovieStatus> MovieStatusParser;
	static void Split(const std::string&,char, std::vector<std::string>&);
	Utility();
	~Utility();
};

