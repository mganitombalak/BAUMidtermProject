#include <string>

using namespace std;

class MenuItem
{
	std::string* Title;
	int DisplayOrder;
	MenuItem* ParentMenu;
public:
	
	MenuItem(void);
	explicit MenuItem(std::string*,MenuItem*,int);
	~MenuItem();


	void Print(bool) const;
	MenuItem* getParentMenu(void)const;
	int getDisplayOrder(void)const;
};

