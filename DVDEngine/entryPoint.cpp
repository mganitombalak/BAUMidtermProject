#include  <stdio.h>
#include "Headers/Date.h"
#include <iostream>
#include "Headers/Utility.h"
#include "Headers/FileDataAdapter.h"
#include "Headers/Movie.h"
#include "Headers/ApplicationManager.h"
#include "Headers/Global.h"

int main(int argc, char* args[])
{
    const string* filePath = new string("/Users/mehmetganitombalak/Downloads/DVD_list.txt");
    ApplicationManagerHandler = new ApplicationManager(filePath);
    ApplicationManagerHandler->PrepareMenuTree();
    ApplicationManagerHandler->ShowAndAskForMainMenu();
	return 0;
}
