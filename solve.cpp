#include <iostream>
#include <cstring>
#include "Sudoku.h"
#include <cstdlib>
#include<time.h>
#include<cstdio>
using namespace std;

int main()
{
	Sudoku sdk;
	sdk.readIn();
	sdk.solve();
	system("PAUSE");
	return 0;
}
