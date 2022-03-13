#include <iostream>

using namespace std;

int main() {
	long long elPP, elP, el; elP = el = 2;
	int N;
	cin >> N;
	if (N <= 2) {
		cout << 2;
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		elPP = elP;
		elP = el;
		el = elPP + elP;
	}
	cout << el;
}