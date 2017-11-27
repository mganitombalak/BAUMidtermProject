#pragma once
#include "MenuItem.h"
#include "FileDataAdapter.h"

class ApplicationManager
{
private:
	MenuItem* menuList;
	
public:
	FileDataAdapter<Movie>* fda;
	void ShowAndAskForMainMenu(void) const;
	void PrepareMenuTree(void) const;
	MenuItem* FindMenu(MenuItem*,int) const;
	void ShowSubMenu(MenuItem* ParentMenu) const;
	ApplicationManager(const string*);
	~ApplicationManager();
};

