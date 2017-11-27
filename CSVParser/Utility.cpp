#include <iostream>
#include "Headers/Utility.h"

using namespace std;

void Utility::Split(const std::string& splittingText, char delimiter, std::vector<std::string>& splittedText)
{
	std::string::size_type i = 0;
	std::string::size_type j = splittingText.find(delimiter);
	while (j != std::string::npos) {
		splittedText.push_back(splittingText.substr(i, j - i));
		i = ++j;
		j = splittingText.find(delimiter, j);

		if (j == std::string::npos)
			splittedText.push_back(splittingText.substr(i, splittingText.length()));
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

void Utility::SetCursorPosition(int, int) {

}

void Utility::PrintMenuHeader(std::string title) {
	PrintOneLineBorder();
	cout << string(1, 124) << string(28, 32) << title << string(28, 32) << string(1, 124) << endl;
	PrintOneLineBorder();
}

void Utility::PrintOneLineBorder() {
    cout << string(1,91) << string(60, 61) << string(1, 93) << endl;
}
