#include "Utility.h"


void Utility::Split(const std::string& splittingText, char delimeter, std::vector<std::string>& splitedText)
{
	std::string::size_type i = 0;
	std::string::size_type j = splittingText.find(delimeter);
	while (j != std::string::npos) {
		splitedText.push_back(splittingText.substr(i, j - i));
		i = ++j;
		j = splittingText.find(delimeter, j);

		if (j == std::string::npos)
			splitedText.push_back(splittingText.substr(i, splittingText.length()));
	}
}

Utility::Utility(){}


Utility::~Utility() {}
