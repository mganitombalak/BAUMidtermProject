#include "MenuItem.h"
#include <iostream>
using namespace std;

MenuItem::MenuItem(std::string* menuTitle,int displayOrder)
{
	Title = menuTitle;
	DisplayOrder = displayOrder;
}

MenuItem::MenuItem():Title(nullptr),DisplayOrder(0)
{
}

void MenuItem::Print() const
{
	cout <<"("<< this->DisplayOrder + 1 << ") "<< *(this->Title) << endl;
}

MenuItem* MenuItem::getParentMenu() const
{
	return ParentMenu;
}

MenuItem::MenuItem(std::string* menuTitle, MenuItem* parentMenu,int displayOrder)
{
	ParentMenu = parentMenu;
	Title = menuTitle;
	DisplayOrder = displayOrder;
}

MenuItem::~MenuItem()
{
	delete ParentMenu;
	delete Title;
}
template<class T, class F>
F for_each(T first, T last, F f)
{
	for (; first != last; ++first) {
		f(*first);
	}
	return f;
}
