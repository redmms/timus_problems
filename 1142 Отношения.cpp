#include <iostream>
#include <vector>
using namespace std;
int fact(int a) {
	if (a == 0)
		return 0;
	int res = 1;
	for (int i = 1; i <= a; i++) {
		res *= i;
	}
	return res;
}
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	vector <vector <int>> StN(11, vector <int> (11)); 
	vector <int> list;
	int ans, vv;
	StN[0][0] = 1;
	for (int n = 1; n <= 10;) {
		for (int k = 0; k <= 10; k++) {
			if (k == n) {
				StN[n][k] = 1;
				n++;
				break;
			}
			else if (k == 0)
				StN[n][k] = 0;
			else if (k == 1) {
				StN[n][k] = 1;
			}
			else
				StN[n][k] = k*StN[n - 1][k] + StN[n - 1][k - 1];
		}
	}
	//for (int i = 0; i <= 10; i++) {
	//	for (int j = 0; j <= 10; j++) {
	//		cout << StN[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	for (int n = 2; n <= 10; n++) {
		ans = 0;
		for (int k = 1; k <= n; k++) {
			ans += fact(k) * StN[n][k];
		}
		list.push_back(ans);
	}
	while (cin >> vv && vv != -1) {
		cout << list[vv - 2] << '\n';
	}
}