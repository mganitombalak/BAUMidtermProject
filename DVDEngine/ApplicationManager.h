#pragma once
#include "MenuItem.h"

class ApplicationManager
{
private:
	MenuItem* menuList;
public:
	void ShowAndAskForMainMenu(void) const;
	void PrepareMenuTree(void) const;
	MenuItem* FindMenu(MenuItem*,int) const;
	void ShowSubMenu(MenuItem* ParentMenu) const;
	ApplicationManager(void);
	~ApplicationManager();
};

