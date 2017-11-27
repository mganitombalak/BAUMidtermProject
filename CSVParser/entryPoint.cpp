
#include "Headers/ApplicationManager.h"
#include "Headers/Global.h"

ApplicationManager* applicationManager;
int main(int argc, char* args[])
{
    const string* filePath = new string("/Users/mehmetganitombalak/Downloads/DVD_list.txt");
    applicationManager = new ApplicationManager(filePath);
    applicationManager->PrepareMenuTree();
    applicationManager->ShowAndAskForMainMenu();
	return 0;
}
