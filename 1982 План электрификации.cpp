#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector <int> elstations(k + 1); vector <vector <int>> ceny(n + 1, vector <int>(n + 1));
	for (int i = 1; i <= k; i++) {
		cin >> elstations[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ceny[i][j];
		}
	}
	for (auto i = elstations.begin() + 1; i != elstations.end(); i++) {
		for (auto j = elstations.begin() + 1; j != elstations.end(); j++) {
			if (*i != *j)
				ceny[*i][*j] = ceny[*j][*i] = 0;
		}
	}
	int ans = 0;
	for (;;) {
		int MIN = INT_MAX, mini, minj; bool pusto = true;
		for (auto is = elstations.begin() + 1; is != elstations.end(); is++) {
			for (auto ic = ceny[*is].begin() + 1; ic != ceny[*is].end(); ic++) {
				if (*ic < MIN && *ic != 0) {
					MIN = *ic;
					minj = distance(ceny[*is].begin(), ic);
					pusto = false;
				}
			}
		}
		if (pusto)
			break;
		ans += MIN;
		for (auto is = elstations.begin() + 1; is != elstations.end(); is++) {
			ceny[minj][*is] = ceny[*is][minj] = 0;
		}
		elstations.push_back(minj);
	}
	cout << ans;
}