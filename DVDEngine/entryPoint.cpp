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
	appMgr = new ApplicationManager;
	appMgr->PrepareMenuTree();
	const string* filePath = new string("D:\\DVD_List.txt");
	const FileManager* fm = new FileManager(filePath, ios::in);
	fda = new FileDataAdapter<Movie>(fm);
	fda->Execute(true);
	appMgr->ShowAndAskForMainMenu();
	string s;
	cin >> s;
	return 0;
}
