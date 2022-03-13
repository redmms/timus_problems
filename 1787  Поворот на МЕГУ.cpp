#include <iostream>

using namespace std;

int main() {
	int k, n, a, ans, Summ = 0;

	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		Summ += a;
		if (k <= Summ)
			Summ -= k;
		else Summ = 0;
	}
	cout << Summ;
}