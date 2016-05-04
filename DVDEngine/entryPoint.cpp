#include  <stdio.h>
#include "Date.h"
#include <iostream>
#include "Utility.h"
#include "FileDataAdapter.h"
#include "Movie.h"

int main(const string args[])
{
	Movie m("Painted Veil (1934/ Archive Collection/ On Demand DVD-R)	Out	$21.99	1934	Drama	6/11/2013	262949");
	m.Parse();
	if (args->length() <= 0) return -1;
	const auto filePath=&args[0];
	const auto fm =new FileManager(filePath,ios::out);
	auto f = new FileDataAdapter<Movie>(fm);
	return 0;
}
