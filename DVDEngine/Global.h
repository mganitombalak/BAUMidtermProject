#include "FileDataAdapter.h"

static ApplicationManager* appMgr;

void filterByTitle();
void filterByID();
void compareByPrice();
void groupByGenre();
void groupCountByGenre();
void calcAvgPrice();
void filterByPriceGreaterThen();
void calcAvgPriceByGenre();
void filterByDateGreaterThen();

using namespace std;


inline void filterByTitle()
{
	system("cls");
	std::cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(26, 176) << " TITLE FILTER " << string(26, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	string title;
	while (!title.empty())
	{
		cout << "Please enter a title to search(type '#' to main menu):" << ends;
		cin >> title;
		if (title[0] == '#')
		{
			appMgr->ShowAndAskForMainMenu();
			return;
		}
		string headers[] = { "ID","Title" };
		Utility::PrintGridHeaders(headers);
		for (Movie m : appMgr->fda->getResultSet())
		{
			if (m.getDVD_Title().find(title) != string::npos)
			{
				m.Print();
			}
		}
	}

}

inline void filterByID()
{
	system("cls");
	std::cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(23, 176) << " ID FILTER " << string(23, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	int selectedID = -1;
	string input;
	while (input == "" || input.empty())
	{
		try
		{
			cout << "Please enter a movieID to search(type '#' to main menu):" << ends;
			cin >> input;
			if (input[0] == '#')
			{
				appMgr->ShowAndAskForMainMenu();
				return;
			}
			selectedID = stoi(input);
		}
		catch (...)
		{
			input = "";
		}

	}
	string headers[] = { "ID","Title","Status","Genre","Price","Year","Release Date", };
	Utility::PrintGridHeaders(headers);
	for (Movie m : appMgr->fda->getResultSet())
	{
		if (m.getID() == selectedID);
		{
			m.Print();
		}
	}
}

inline void compareByPrice()
{
}

inline void groupByGenre()
{
}

inline void groupCountByGenre()
{
}

inline void calcAvgPrice()
{
}

inline void filterByPriceGreaterThen()
{
}

inline void calcAvgPriceByGenre()
{
}

inline void filterByDateGreaterThen()
{
}
