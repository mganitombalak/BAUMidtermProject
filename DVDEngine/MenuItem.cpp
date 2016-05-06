#include <iostream>
#include "MenuItem.h"

using namespace std;

MenuItem::MenuItem() :Title(nullptr), DisplayOrder(0), ParentMenu(nullptr)
{
}

void MenuItem::Print(bool addBorder = false) const
{
	if (addBorder)
	{
		int length = 54 - this->Title->length();
		length = length < 0 ? length*-1 : length;
		cout << "(" << this->DisplayOrder + 1 << ") " << *(this->Title) << ends;
		cout << string(length, 32) << string(1, 186) << endl;;
	}
	else
		cout << "(" << this->DisplayOrder + 1 << ") " << *(this->Title) << endl;
}

MenuItem* MenuItem::getParentMenu() const
{
	return ParentMenu;
}

int MenuItem::getDisplayOrder() const
{
	return DisplayOrder;
}

MenuItem::MenuItem(string* menuTitle, MenuItem* parentMenu, int displayOrder)
{
	Title = menuTitle;
	DisplayOrder = displayOrder;
	ParentMenu = parentMenu;
}

MenuItem::~MenuItem()
{
	delete ParentMenu;
	delete Title;
}