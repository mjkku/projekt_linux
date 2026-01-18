#include <iostream>
#include <string>
using namespace std;

int main(){
	char board[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};

	const char playerX = 'X';
	const char playerO = 'O';
	char currentPlayer = playerX;
	int row = -1;
	int col = -1;
	char winner = ' ';

	cout << "*****************************************************************************" << endl;
	cout << "Witam w grze kółko i krzyżyk! "<< endl;
	cout << "**********************************";
	cout << "\033[31mINSTRUKCJA\033[0m";
	cout << "*********************************" << endl;
	cout << "--> Dwóch graczy: X i O\n--> W każdej rundzie zostaniesz poproszony o podanie numeru wiersza i kolumny: " << endl;
	cout << "	  - najpierw podaj nr wiersza (1-3)" << endl;
	cout << "	  - potem po spacji - nr kolumny (1-3)" << endl;
	cout << "np. podaj wartości od 1-3 dla wiersza i kolumny: " << "wpisujesz \033[32m1 1\033[0m" << endl;
	cout << "******************************************************************************\n" << endl;

	for (int i = 0; i < 9; i++) {

		if (i > 0) {
			cout << "\033[3J\033[2J\033[H" << flush;
		}

		//drukowanie siatki
		cout << "   |   |   " << endl;
		cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
		cout << "   |   |   " << endl;

		if (winner != ' ') {
			break;
		}

		cout << "kolej gracza " << currentPlayer << endl;
		while (true) {
			cout << "podaj wartości od 1-3 dla wiersza i kolumny:";
			cin >> row >> col;

			row--;
			col--;

			if (row < 0 || row > 2 || col < 0 || col > 2) {
				cout << "zła wartość, spróbuj ponownie" << endl;
			}
			else if (board[row][col] != ' ') {
				cout << "miejsce zajęte, spróbuj ponownie" << endl;
			}
			else {
				break;
			}
			row = -1;
			col = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		board[row][col] = currentPlayer;
		currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

		for (int row = 0; row < 3; row++) {
			if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
				winner = board[row][0];
				break;
			}
		}
		for (int col = 0; col < 3; col++) {
			if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
				winner = board[0][col];
				break;
			}
		}
		if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			winner = board[0][0];
		}
		else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			winner = board[0][2];
		}
	}
	if (winner != ' ') {
		cout << "gracz " << winner << " wygrał!" << endl;
	}
	else {
		cout << "REMIS" << endl;
	}
}
