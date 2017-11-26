#include <iostream>
#include "Headers/MenuItem.h"

using namespace std;

MenuItem::MenuItem() :Title(nullptr), DisplayOrder(0), ParentMenu(nullptr),onSelected(nullptr)
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

MenuItem::MenuItem(string* menuTitle, MenuItem* parentMenu, int displayOrder, void(*handler)())
{
	Title = menuTitle;
	DisplayOrder = displayOrder;
	ParentMenu = parentMenu;
	onSelected = handler;
}

MenuItem::~MenuItem()
{
	delete ParentMenu;
	delete Title;
}

bool MenuItem::hasFunction()
{
	return this->onSelected != nullptr;
}

void(* MenuItem::getFunction())()
{
	return this->onSelected;
}
