#include <string>

using namespace std;

class MenuItem
{
	std::string* Title;
	int DisplayOrder;
	MenuItem* ParentMenu;
	void(*onSelected)();
public:
	
	MenuItem(void);
	explicit MenuItem(std::string*,MenuItem*,int, void(*onSelected)());
	~MenuItem();

	bool hasFunction();
	void(*getFunction()) ();
	void Print(bool) const;
	MenuItem* getParentMenu(void)const;
	int getDisplayOrder(void)const;
};

