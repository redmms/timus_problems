#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	long double ans = 0.0; int n;
	cin >> n;
	vector <long double> m(n);
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	if (n == 1) {
		cout << fixed << setprecision(2) << m[0];
		return 0;
	}
	sort(m.rbegin(), m.rend());
	for (int i = 0; i < n - 1; i++) {
		ans = 2 * sqrt(m[i] * m[i + 1]);
		m[i + 1] = ans;
	}
	cout << fixed << setprecision(2) << ans;
}