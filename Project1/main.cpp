int main() {
	Sudoku sdk;
	sdk.giveQuestion();
	sdk.readIn();
	sdk.solve();
	system("PAUSE");
	return EXIT_SUCCESS;
}