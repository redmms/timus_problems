#include <iostream>

using namespace std;

int main() {
	int N, Chislo, Kolvo = 1, Pr, Num;
	cin >> N;
	cin >> Num;
	if (N == 1) {
		cout << 1 << " " << Num;
		return 0;
	}
	Pr = Num;
	Chislo = Num;
	for (int i = 2; i <= N; i++) {
		cin >> Num;
		if (Num == Pr) {
			Kolvo++;
		}
		if (Num != Pr) {
			cout <<Kolvo  << " " <<  Chislo<< " ";
			Chislo = Num;
			Kolvo = 1;
		}
		if (i == N) {
			cout << Kolvo << " " << Chislo;
		}
		Pr = Num;
	}
}