#include <iostream>

using namespace std;



int main() {
	int N, M, Y, X, switcher = 0;
	auto Ost = [&N, &M](int X) {
		long long Ost = X%M, OstX = X%M;
		for (int i = 2; i <= N; i++) {
			Ost = (Ost*OstX)%M;
		}
		return Ost;
	};
	cin >> N >> M >> Y;
	for (X = 0; X < M; X++) {
		if (Ost(X)%M == Y) {
			cout << X << " ";
			if (switcher != 1)
				switcher = 1;
		}
	}
	if (switcher == 0)
		cout << -1;
}