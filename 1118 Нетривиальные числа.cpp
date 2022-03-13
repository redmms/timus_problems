#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n = 1000002;
vector<char> prime(n + 1, true);
void eratosphen() {
	prime[0] = false;
	prime[1] = false;
	for (int i1 = 2; i1 <= n; ++i1)
		if (prime[i1])
			if (i1 * 1ll * i1 <= n)
				for (int j1 = i1 * i1; j1 <= n; j1 += i1)
					prime[j1] = false;
}
int main() {
	long long i, j; double ans = 1; map <long long, double> vvod;
	long long iDel, iV, vyvod = 0; double minAns = 9999999;
	cin >> i >> j;
	if (i == 1) {
		cout << 1;
		return 0;
	}
	else if (i == j) {
		cout << i;
		return 0;
	}
	eratosphen();
	for (long long iV = j % 2 != 0 ? j : j - 1; iV >= i; iV -= 2) {
		if (prime[iV]) {
			cout << iV;
			return 0;
		}
	}
	for (long long iV = i; iV <= j; iV++) {
		vvod[iV] = 1;
	}
	for (iDel = 2; iDel <= j / 2 + 1; iDel++) {
		for (iV = i; iV <= j; iV++) {
			if (iV == iDel)
				break;
			if (iV%iDel == 0) {
				vvod[iV] += iDel;
			}
		}
	}
	for (long long iV = i; iV <= j; iV++) {
		vvod[iV] /= iV;

	}
	for (long long iV = i; iV <= j; iV++) {
		if (vvod[iV] < minAns) {
			minAns = vvod[iV];
			vyvod = iV;
		}
	}
	cout << vyvod;
}