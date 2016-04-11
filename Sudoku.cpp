#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;
int mapin[9][9];
int output[9][9];
int simple[81][9];
int times = 0;
int ans;

void Sudoku::giveQuestion() {
	int i, j;

	int question[9][9] = {
		{ 8, 5, 1, 6, 3, 0, 0, 2, 4 },
		{ 4, 3, 2, 1, 9, 5, 8, 0, 7 },
		{ 9, 7, 6, 0, 4, 2, 0, 1, 5 },
		{ 6, 0, 3, 7, 5, 1, 0, 9, 2 },
		{ 5, 4, 0, 0, 2, 0, 7, 0, 1 },
		{ 1, 0, 7, 9, 8, 4, 6, 0, 3 },
		{ 0, 0, 0, 5, 0, 0, 0, 4, 6 },
		{ 3, 0, 4, 2, 6, 0, 0, 7, 8 },
		{ 0, 6, 0, 0, 7, 8, 0, 3, 0 }
	};

	//開始印出題目

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << question[i][j] << ' ';
		}
		cout << "\n";
	}
}

void Sudoku::readIn() {
	int i, j;
	int mapin[9][9];
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			cin >> mapin[i][j];
		}
	}
		
}
void judge(int i, int j){
	times++;
	int x, y, num;
	int k = 0, l = 0, a = 0, b = 0;
	//建立一個樣本矩陣 代表可填入的數字 預設為1到9
	for (num = 0; num < 9; num++){
		simple[times][num] = num + 1;
	}
	//檢查同行內有無重複數字 有重複 則從樣本矩陣simple中 將該數字改成0 (在樣本矩陣中移除他)
	for (x = 0; x < 9; x++){
		for (num = 0; num < 9; num++){
			
				if (mapin[i][x] == simple[times][num])
				{
					simple[times][num] = 0;
				}
			}
	}
	//檢查同列內有無重複數字 有重複 則從樣本矩陣simple中 將該數字改成0 (在樣本矩陣中移除他)
	for (y = 0; y < 9; y++){
		for (num = 0; num < 9; num++){
				if (mapin[y][j] == simple[times][num])
				{
					simple[times][num] = 0;
				}
			}
		
	}
	//接下來檢查同個方格有無重複數字 有重複則從樣本矩陣simple刪除該數字
	
	//限定方格的範圍
	if (i <= 2){ k = 0; }
	else if (i > 5){ k = 6; }
	else { k = 3; }

	if (j <= 3){ l = 0; }
	else if (j > 5){ l = 6; }
	else { l = 3; }
	for (a = k; a < (k + 3); a++){
		for (b = l; b < (l + 3); b++){
			for (num = 0; num < 9; num++){
					if (mapin[a][b] == simple[times][num])
					{
						simple[times][num] = 0;
					}
				}
			}
		}
	
}

void Sudoku::solve(){
	int i, j;
	nooutput();

	if (ans== 2){ goto noans; }
	if (output[1][1] == 0)
	{
		cout << endl << "0" << endl << endl;
		goto noans;
	}
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
noans:
	if (ans == 1)
	{
		cout << endl << "1" << endl << endl;
	}
}


void Sudoku::nooutput() {
	int  i, j, k;
	int  m, n;
	int solve[81][9]; //此為篩選過後的樣本矩陣simple(避免動到原本的simple)
	int space = 0;
	//space代表有幾個空格
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			if (mapin[i][j] == 0){ space++; }
		}
	}
	//先用迴圈找出有幾格空格
	//當space=0 為solve的結束條件 代表所有空格都被填入了數字
	if (space == 0){
		ans++;
		if (ans == 2){
			cout << endl << "2" << endl << endl;
			exit(0);
		}
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				output[i][j] = mapin[i][j];
			}
		}
		for (i = 0; i<9; i++)
		{
			for (j = 0; j<9; j++)
			{
				cout << output[i][j] << " ";
			}
			cout << endl;
		}
		system("PAUSE");

	}
	else{
		//填入數字的遞迴
		for (m = 0; m < 9; m++)
		{//行
			for (n = 0; n < 9; n++)
			{//列
				if (mapin[m][n] == 0)
				{
					judge(m, n);

					for (k = 0; k < 9; k++)
					{
						solve[times][k] = simple[times][k];//把樣本矩陣剩下的數字存進solve
					}
					for (k = 0; k < 9; k++)
					{
						if (solve[times][k] != 0)//找到solve陣列中不是0的數字 開始填入mapin
						{
							mapin[m][n] = solve[times][k];
							nooutput();   //遞迴呼叫
							mapin[m][n] = 0;
							times--;
						}
					}
					return;
				}
			}
		}
	}
}
	


void Sudoku::changeNum(int a, int b) {
	int i, j;
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			if (mapin[i][j] == a)
				mapin[i][j] = b;
			else if (mapin[i][j] == b)
				mapin[i][j] = a;
		}
	}
}

void Sudoku::changeRow(int a, int b) {
	// 0~ab~2
	int i,j, tem;
	if (a == 1)
		a = a + 2;
	if (b == 1)
		b = b + 2;
	if (a == 2)
		a = a + 4;
	if (b == 2)
		b = b + 4;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 9; j++){
			tem = mapin[a][j];
			mapin[a][j] = mapin[b][j];
			mapin[b][j] = tem;
			}
			a++;
			b++;
	}
}



void Sudoku::changeCol(int a, int b){
	int i, j, tem;
	if (a == 1)
		a = a + 2;
	if (b == 1)
		b = b + 2;
	if (a == 2)
		a = a + 4;
	if (b == 2)
		b = b + 4;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 9; j++){
			tem = mapin[j][a];
			mapin[j][a] = mapin[j][b];
			mapin[j][b] = tem;
		}
		a++;
		b++;
	}
}

void Sudoku::rotate(int n) {
	int rotated[9][9];
	int i, j, k, x;
	
	k = n % 4;
	for (x = 0; x < k; x++){
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				rotated[j][8 - i] = mapin[i][j];
			}
		}
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				mapin[i][j] = rotated[i][j];
			}
		}
	}
}

void Sudoku::flip(int n) {
	//0 vertically
	//1 horizontally
	int i, j, tem;
	int a = 3;
	int b = 5;

	if (n == 0){
		for (i = 0; i < 4; i++){
			for (j = 0; j < 9; j++){
				tem = mapin[a][j];
				mapin[a][j] = mapin[b][j];
				mapin[b][j] = tem;
			}
			a--;
			b++;
		}

	}
	if (n == 1){
		for (i = 0; i < 4; i++){
			for (j = 0; j < 9; j++){
				tem = mapin[j][a];
				mapin[j][a] = mapin[j][b];
				mapin[j][b] = tem;
			}
			a--;
			b++;
		}
	}
}

void Sudoku::trans(){
	srand(time(NULL));
	changeNum((rand() % 9 + 1), (rand() % 9 + 1));
	changeRow(rand() % 3, rand() % 3);
	changeCol(rand() % 3, rand() % 3);
	rotate(rand() % 101);
	flip(rand() % 2);
}

void Sudoku::transform() {
	int i, j;
	readIn();
	trans();
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			cout << mapin[i][j] << " ";
		}cout << endl;
	}

}

