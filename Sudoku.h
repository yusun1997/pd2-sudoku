using namespace std;

class Sudoku
{
public:
	void giveQuestion();
	void readIn();
	void solve();
	void nooutput();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void transform();
	int checkRow(int num, int j);
	int checkCol(int num, int i);
	int checkSqu(int num, int i, int j);
	void trans();
};