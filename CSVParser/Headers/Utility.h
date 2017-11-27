#pragma once
#include <string>
#include <vector>
#include <map>
#include "MovieStatus.h"

class Utility
{
public:
	const static char Delimiter='\t';
	std::map<std::string, MovieStatus> MovieStatusParser;
	static void Split(const std::string&,char, std::vector<std::string>&);
	static void SetCursorPosition(int,int);
	static void PrintGridHeaders(std::string[]);
	static void PrintMenuHeader(std::string);
    static void PrintOneLineBorder();
	template<typename  ArrayType,size_t n>
	static size_t ArraySize(ArrayType(&)[n]){return n;}

	Utility();
	~Utility();
};

