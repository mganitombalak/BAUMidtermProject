#include "Headers/Utility.h"


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

void Utility::PrintGridHeaders(std::string[])
{

}

Utility::Utility()
{
	MovieStatusParser["Out"] = MovieStatus::Out;
	MovieStatusParser["Cancelled"] = MovieStatus::Cancelled;
	MovieStatusParser["Discontinued"] = MovieStatus::Discontinued;
}


Utility::~Utility() {}