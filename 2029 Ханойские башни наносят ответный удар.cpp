#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main() {
	int n, crntpos = 1; char vv; long long ans = 0;
	cin >> n;
	vector <int> twrs(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> vv;
		twrs[i] = vv - '@';
	}
	for (int ni = n; ni >= 1; ni--) {
		if (crntpos != twrs[ni]) {
			ans += 1LL << (ni - 1);
			crntpos = crntpos ^ twrs[ni];
		}
	}
	cout << ans;
}