#pragma once
#include <string>

class MenuItem
{
	MenuItem* ParentMenu;
	std::string* Title;
	int DisplayOrder;
public:
	
	explicit MenuItem(std::string*,int);
	MenuItem();
	MenuItem(std::string*,MenuItem*,int);
	~MenuItem();


	void Print() const;
	MenuItem* getParentMenu()const;
};

