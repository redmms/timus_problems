#include <iostream>

using namespace std;

int main() {
	int n, Summ = 0;

	cin >> n;
	if (n < 1)
		for (n; n <= 1; n++) {
			Summ += n;
		}
	else
		for (int i = 1; i <= n; i++) {
			Summ += i;
		}
	cout << Summ;
}