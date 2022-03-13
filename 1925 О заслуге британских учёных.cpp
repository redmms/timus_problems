#include <iostream>
using namespace std;
int main() {
	int n, k, b, g, SumB = 0, SumG = 0, Diff;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> b >> g;
		SumB += b; SumG += g;
	}

	Diff = (SumB - SumG) - n * 2;
	k = k- 2 + Diff;
	if (Diff <= k && k >= 0)
		cout << k;
	else
		cout << "Big Bang!";
}