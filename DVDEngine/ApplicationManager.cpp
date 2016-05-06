#include <vector>
#include "ApplicationManager.h"
#include "Utility.h"
#include <iostream>
using namespace std;

void ApplicationManager::PrepareMenuTree() const
{

#pragma region First Group

	menuList[0] = *(new MenuItem(new string("Search and display a movie"), nullptr, 0));
	menuList[1] = *(new MenuItem(new string("By DVD Title"), &menuList[0], 0));
	menuList[2] = *(new MenuItem(new string("By ID"), &menuList[0], 1));

#pragma endregion 

#pragma region Second Group

	menuList[3] = *(new MenuItem(new string("Compare two movies based on their price information"), nullptr, 1));
#pragma endregion 

#pragma region Third Group

	menuList[4] = *(new MenuItem(new string("List movies based on genre"), nullptr, 2));
	menuList[5] = *(new MenuItem(new string("Suspense"), &menuList[4], 0));
	menuList[6] = *(new MenuItem(new string("Foreign"), &menuList[4], 1));
	menuList[7] = *(new MenuItem(new string("Comedy"), &menuList[4], 2));
	menuList[8] = *(new MenuItem(new string("Western"), &menuList[4], 3));
	menuList[9] = *(new MenuItem(new string("Music"), &menuList[4], 4));
	menuList[10] = *(new MenuItem(new string("Drama"), &menuList[4], 5));

#pragma endregion 

#pragma region Fourth Group

	menuList[11] = *(new MenuItem(new string("Display Statistics"), nullptr, 3));
	menuList[12] = *(new MenuItem(new string("Display number of each genres"), &menuList[11], 0));
	menuList[13] = *(new MenuItem(new string("Display average price"), &menuList[11], 1));
	menuList[14] = *(new MenuItem(new string("Display the number of movies whose price is greater than ..."), &menuList[11], 2));
	menuList[15] = *(new MenuItem(new string("Display average price of \"Discontinued\" movies"), &menuList[11], 3));
	menuList[16] = *(new MenuItem(new string("Display average price of \"Out\" movies"), &menuList[11], 4));
	menuList[17] = *(new MenuItem(new string("Display average price of \"Cancelled\" movies"), &menuList[11], 5));
	menuList[18] = *(new MenuItem(new string("Drama"), &menuList[11], 6));

#pragma endregion 

#pragma region Fifth Group
	menuList[19] = *(new MenuItem(new string("Display movies after an input date"), nullptr, 4));
#pragma endregion 

#pragma region Sixth Group
	menuList[20] = *(new MenuItem(new string("Exit"), nullptr, 5));
#pragma endregion 

}


void ApplicationManager::ShowAndAskForMainMenu() const
{
	system("cls");
	for (auto i = 0; i < 20; i++)
	{
		if (menuList[i].getParentMenu() != nullptr) continue;
		menuList[i].Print();
	}
	int intSelection;
	MenuItem* choosen = static_cast<MenuItem*>(nullptr);
	while (!choosen)
	{
		try
		{
			cout << "Please enter your choice:" << ends;
			string selection;
			cin >> selection;

			intSelection = stoi(selection);
			choosen = FindMenu(nullptr, intSelection - 1);
		}
		catch (...)
		{

		}
	}
	ShowSubMenu(choosen);
}

void ApplicationManager::ShowSubMenu(MenuItem* ParentMenu) const
{
	system("cls");
	for (auto i = 0; i < 20; i++)
	{
		if (menuList[i].getParentMenu() == nullptr) continue;
		else if (menuList[i].getParentMenu() == ParentMenu)
			menuList[i].Print();
	}
	cout << "Please enter your choice (type '#' to go back):" << ends;
	int intSelection;
	MenuItem* choosen = static_cast<MenuItem*>(nullptr);
	while (!choosen)
	{
		try
		{
			string selection;
			cin >> selection;
			if (selection[0] == '#')
				ShowAndAskForMainMenu();
			intSelection = stoi(selection);
			choosen = FindMenu(ParentMenu, intSelection);
		}
		catch (...)
		{

		}
	}
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

ApplicationManager::ApplicationManager()
{
	menuList = allocator<MenuItem>().allocate(20);
}


ApplicationManager::~ApplicationManager()
{
	delete[] menuList;
}
