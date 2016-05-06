#include <iostream>
#include <vector>
#include "ApplicationManager.h"
#include "Utility.h"
#include <windows.h>
#include "Movie.h"
#include "Global.h"

using namespace std;
void(*handler)();
void ApplicationManager::PrepareMenuTree() const
{
#pragma region First Group

	menuList[0] = *(new MenuItem(new string("Search and display a movie"), nullptr, 0,  nullptr));
	handler = &filterByTitle;
	menuList[1] = *(new MenuItem(new string("By DVD Title"), &menuList[0], 0,  handler));
	handler = &filterByID;
	menuList[2] = *(new MenuItem(new string("By ID"), &menuList[0], 1,  handler));

#pragma endregion 

#pragma region Second Group

	menuList[3] = *(new MenuItem(new string("Compare two movies based on their price information"), nullptr, 1,  nullptr));
#pragma endregion 

#pragma region Third Group

	menuList[4] = *(new MenuItem(new string("List movies based on genre"), nullptr, 2,  nullptr));
	menuList[5] = *(new MenuItem(new string("Suspense"), &menuList[4], 0, nullptr));
	menuList[6] = *(new MenuItem(new string("Foreign"), &menuList[4], 1,  nullptr));
	menuList[7] = *(new MenuItem(new string("Comedy"), &menuList[4], 2,  nullptr));
	menuList[8] = *(new MenuItem(new string("Western"), &menuList[4], 3,  nullptr));
	menuList[9] = *(new MenuItem(new string("Music"), &menuList[4], 4, nullptr));
	menuList[10] = *(new MenuItem(new string("Drama"), &menuList[4], 5, nullptr));

#pragma endregion 

#pragma region Fourth Group

	menuList[11] = *(new MenuItem(new string("Display Statistics"), nullptr, 3, nullptr));
	menuList[12] = *(new MenuItem(new string("Display number of each genres"), &menuList[11], 0,  nullptr));
	menuList[13] = *(new MenuItem(new string("Display average price"), &menuList[11], 1,  nullptr));
	menuList[14] = *(new MenuItem(new string("Display number of movies whose price is greater than"), &menuList[11], 2, nullptr));
	menuList[15] = *(new MenuItem(new string("Display average price of \"Discontinued\" movies"), &menuList[11], 3,  nullptr));
	menuList[16] = *(new MenuItem(new string("Display average price of \"Out\" movies"), &menuList[11], 4,  nullptr));
	menuList[17] = *(new MenuItem(new string("Display average price of \"Cancelled\" movies"), &menuList[11], 5,  nullptr));
	menuList[18] = *(new MenuItem(new string("Drama"), &menuList[11], 6, nullptr));

#pragma endregion 

#pragma region Fifth Group
	menuList[19] = *(new MenuItem(new string("Display movies after an input date"), nullptr, 4, nullptr));
#pragma endregion 

#pragma region Sixth Group
	menuList[20] = *(new MenuItem(new string("Exit"), nullptr, 5, nullptr));
#pragma endregion 

}

void ApplicationManager::ShowAndAskForMainMenu() const
{
	system("cls");
	cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(26, 176) << " MENU " << string(26, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	for (auto i = 0; i < 20; i++)
	{
		if (menuList[i].getParentMenu() != nullptr) continue;
		cout << string(1, 186) << ends;
		menuList[i].Print(true);
	}
	cout << string(1, 200) << string(60, 205) << string(1, 188) << endl;
	int intSelection;
	MenuItem* choosen = static_cast<MenuItem*>(nullptr);
	while (!choosen)
	{
		try
		{
			cout << "Please enter your choice(type 'exit' to exit):" << ends;
			string selection;
			cin >> selection;
			if (selection == "Exit" || selection == "exit")
				exit(0);
			intSelection = stoi(selection);
			choosen = FindMenu(nullptr, intSelection - 1);
		}
		catch (...)
		{
			choosen = nullptr;
		}
	}
	cout << string(1, 200) << string(60, 205) << string(1, 188) << endl;
	if (choosen->hasFunction())
		choosen->getFunction()();
	else
		ShowSubMenu(choosen);
}

void ApplicationManager::ShowSubMenu(MenuItem* ParentMenu) const
{
	system("cls");
	cout << string(1, 201) << string(60, 205) << string(1, 187) << endl;
	cout << string(2, 32) << string(24, 176) << " SUB MENU " << string(24, 176) << string(1, 32) << endl;
	cout << string(1, 204) << string(60, 205) << string(1, 185) << endl;
	for (auto i = 0; i < 20; i++)
	{
		if (menuList[i].getParentMenu() == nullptr) continue;
		else if (menuList[i].getParentMenu() == ParentMenu)
		{
			cout << string(1, 186) << ends;
			menuList[i].Print(true);
		}
	}
	cout << string(1, 200) << string(60, 205) << string(1, 188) << endl;
	int intSelection;
	MenuItem* choosen = static_cast<MenuItem*>(nullptr);
	while (!choosen)
	{
		try
		{
			cout << "Please enter your choice (type '#' to go back):" << ends;
			string selection;
			cin >> selection;
			if (selection[0] == '#')
				ShowAndAskForMainMenu();
			intSelection = stoi(selection);
			choosen = FindMenu(ParentMenu, intSelection-1);
		}
		catch (...)
		{
			choosen = nullptr;
		}
	}
	if (choosen->hasFunction())
		choosen->getFunction()();
}



MenuItem* ApplicationManager::FindMenu(MenuItem* ParentMenu, int DisplayOrder) const
{
	for (auto i = 0; i < 20; i++)
	{
		if (menuList[i].getParentMenu() == ParentMenu & menuList[i].getDisplayOrder() == DisplayOrder)
			return &menuList[i];
	}
	return nullptr;
}

ApplicationManager::ApplicationManager(const string* filePath)
{
	const FileManager* fm = new FileManager(filePath, ios::in);
	menuList = allocator<MenuItem>().allocate(20);
	fda = new FileDataAdapter<Movie>(fm);
	fda->Execute(true);
}


ApplicationManager::~ApplicationManager()
{
	delete[] menuList;
}