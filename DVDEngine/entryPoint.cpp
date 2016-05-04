#include  <stdio.h>
#include "Date.h"
#include <iostream>
#include "Utility.h"
#include "FileDataAdapter.h"
#include "Movie.h"

int main(int argc, char* args[])
{
	const string* filePath=new string("D:\\DVD_List.txt");
	const FileManager* fm =new FileManager(filePath,ios::in);
	auto f = new FileDataAdapter<Movie>(fm);
	f->Execute();
	return 0;
}
