#include "FileDataAdapter.h"
#include "Utility.h"

extern ApplicationManager* applicationManager;

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
	system("clear");
	std::cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(26, 176) << " TITLE FILTER " << string(26, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	string title;
	while (title.empty())
	{
		cout << "Please enter a title to search(type '#' to main menu):" << ends;
		cin >> title;
		if (title[0] == '#')
		{
            applicationManager->ShowAndAskForMainMenu();
			return;
		}
		string headers[] = { "ID","Title" };
		Utility::PrintGridHeaders(headers);
		for (Movie m : applicationManager->fda->getResultSet())
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
	system("clear");
	std::cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(23, 176) << " ID FILTER " << string(23, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	int selectedID = -1;
	string input;
	while (input.empty())
	{
		try
		{
			cout << "Please enter a movieID to search(type '#' to main menu):" << ends;
			cin >> input;
			if (input[0] == '#')
			{
                applicationManager->ShowAndAskForMainMenu();
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
	for (Movie m : applicationManager->fda->getResultSet())
	{
		if (m.getID() == selectedID)
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
	system("clear");
	std::cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(26, 176) << " GENRE GROUP " << string(26, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	int genreid;

	cout << "Please enter GENRE ID (type '#' to main menu):" << ends;
	cin >> genreid;
	if (cin.fail())
	{
        applicationManager->ShowAndAskForMainMenu();
		return;
	}
	string headers[] = { "ID","Title" };
	Utility::PrintGridHeaders(headers);
	switch (genreid)
	{
	case 1:
		for (Movie m : applicationManager->fda->getResultSet())
		{
			if (m.getGenre() == "Suspense")
			{
				m.Print();
			}
		}
		break;
	case 2:
		for (Movie m : applicationManager->fda->getResultSet())
		{
			if (m.getGenre() == "Foreign")
			{
				m.Print();
			}
		}
		break;
	case 3:
		for (Movie m : applicationManager->fda->getResultSet())
		{
			if (m.getGenre() == "Comedy")
			{
				m.Print();
			}
		}
		break;
	case 4:
		for (Movie m : applicationManager->fda->getResultSet())
		{
			if (m.getGenre() == "Western")
			{
				m.Print();
			}
		}
		break;
	case 5:
		for (Movie m : applicationManager->fda->getResultSet())
		{
			if (m.getGenre() == "Music")
			{
				m.Print();
			}
		}
		break;
	case 6:
		for (Movie m : applicationManager->fda->getResultSet())
		{
			if (m.getGenre() == "Drama")
			{
				m.Print();
			}
		}
		break;
	}
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
