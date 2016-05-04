#include  <stdio.h>
#include "Date.h"
#include <iostream>
#include "Utility.h"
#include "FileDataAdapter.h"
#include "Movie.h"

int main(const string args[])
{
	if (args->length() <= 0) return -1;
	const auto filePath=&args[0];
	const auto fm =new FileManager(filePath,ios::out);
	auto f = new FileDataAdapter<Movie>(fm);
	return 0;
}
