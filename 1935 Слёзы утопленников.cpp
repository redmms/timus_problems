#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, ans; 
	cin >> n;
	vector <int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ans = a[0] + a[n - 1];
	for (int i = 0; i < n - 1; i++) {
			ans += max(a[i], a[i + 1]);
	}
	cout << ans;
}