#include <iostream>
#include <cstring>
#include "Sudoku.h"
#include <cstdlib>
#include<time.h>
#include<cstdio>

int main()
{
	Sudoku sdk;
	sdk.readIn();
	sdk.transform();
	system("PAUSE");
	return 0;
}