#include <iostream>

using namespace std;

pair <int, int> UgrP;

char Ugrosy(char table[3][3], char MovingSide, char EvilSide)
{
	int Ugr = 0, ThreeOrNot, vrag, js, is; char a;
	auto what = [&ThreeOrNot, &vrag, &a, &MovingSide, &EvilSide, &is, &js](int i, int j) {
		if (a == MovingSide)
			ThreeOrNot++;
		else if (a == EvilSide)
			vrag++;
		else {
			is = i; js = j;
		}
	};
	auto comp = [&ThreeOrNot, &vrag, &Ugr](int i, int j) {
		if (ThreeOrNot == 2 && vrag == 0) {
			Ugr++;
			UgrP = make_pair(i, j);
		}
	};
	for (int i = 0; i < 3; i++) {
		ThreeOrNot = 0, vrag = 0;
		for (int j = 0; j < 3; j++) {
			a = table[i][j]; what(i, j);
		}
		comp(is, js);
	}
	for (int j = 0; j < 3; j++) {
		ThreeOrNot = 0, vrag = 0;
		for (int i = 0; i < 3; i++) {
			a = table[i][j]; what(i, j);
		}
		comp(is, js);
	}
	ThreeOrNot = 0, vrag = 0;
	for (int it = 0; it < 3; it++) {
		a = table[it][it]; what(it, it);
	}
	comp(is, js);
	ThreeOrNot = 0;	vrag = 0;
	for (int i = 0, j = 2; i < 3; i++, j--) {
		a = table[i][j]; what(i, j);
	}
	comp(is, js);
	return Ugr;
}

int main() {
	int i, Ugr;
	char * a, table[3][3];
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> table[i][j];
		}
	}
	Ugr = Ugrosy(table, 'X', 'O');
	if (Ugr > 0) {
		cout << "Crosses win"; goto stop;
	}
	else {
		Ugr = Ugrosy(table, 'O', 'X');
		if (Ugr > 1) {
			cout << "Ouths win"; goto stop;
		}
		else if (Ugr == 1) {
			table[UgrP.first][UgrP.second] = 'X';
			if (Ugrosy(table, 'X', 'O') == 2) {
				cout << "Crosses win"; goto stop;
			}
		}
		else if (Ugr == 0){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (table[i][j] == '#') {
						a = &(table[i][j] = 'X');
						if (Ugrosy(table, 'X', 'O') == 2 && Ugrosy(table, 'O', 'X') == 0) {
							cout << "Crosses win"; goto stop;
						}
						else
							* a = '#';
					}
				}
			}
		}
	}
	cout << "Draw";
stop:;
}