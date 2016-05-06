﻿#include  <stdio.h>
#include "Date.h"
#include <iostream>
#include "Utility.h"
#include "FileDataAdapter.h"
#include "Movie.h"
#include "ApplicationManager.h"

int main(int argc, char* args[])
{
	ApplicationManager ap;
	ap.PrepareMenuTree();
	const string* filePath=new string("D:\\DVD_List.txt");
	const FileManager* fm =new FileManager(filePath,ios::in);
	auto f = new FileDataAdapter<Movie>(fm);
	//f->Execute(true);
	ap.ShowAndAskForMainMenu();
	string s;
	cin >> s;
	return 0;
}
