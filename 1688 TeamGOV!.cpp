#include <iostream>
using namespace std;
int main() {
cin.sync_with_stdio(false); cin.tie(0);
	long double n, m, sum = 0, vv;
	cin >> n >> m;
	n *= 3;
	for (int i = 1; i <= m; i++) {
		cin >> vv;
		sum += vv;
		if (sum > n) {
			cout << "Free after " << i << " times.";
			return 0;
		}
	}
	cout << "Team.GOV!";
}