#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <vector <int>> a(n, vector <int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = a[0][0];
	for (int leng = 1; leng <= n; leng++){
		for (int up = 0; up <= n-leng; up++){
			vector <long long> sumv(n);
			for (int j = 0; j < n; j++) {
				for (int i = up; i < up + leng; i++) {
					sumv[j] += a[i][j];
				}
			}
			int sum = 0;
			for (int r = 0; r < n; ++r) {
				sum += sumv[r];
				ans = max(ans, sum);
				sum = max(sum, 0);
			}
		}
	}
	cout << ans;
}