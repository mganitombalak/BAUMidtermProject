#pragma once
#include "MenuItem.h"

class ApplicationManager
{
private:
	MenuItem* menuList;
public:
	void ShowMainMenu() const;
	void PrepareMenuTree();
	void ShowSubMenu(MenuItem* ParentMenu) const;
	ApplicationManager();
	~ApplicationManager();
};

