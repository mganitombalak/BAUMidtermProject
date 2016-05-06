#include  <stdio.h>
#include "Date.h"
#include <iostream>
#include "Utility.h"
#include "FileDataAdapter.h"
#include "Movie.h"
#include "ApplicationManager.h"
#include "Global.h"


int main(int argc, char* args[])
{
	const string* filePath = new string("D:\\DVD_List.txt");
	appMgr = new ApplicationManager(filePath);
	appMgr->PrepareMenuTree();
	appMgr->ShowAndAskForMainMenu();
	return 0;
}
