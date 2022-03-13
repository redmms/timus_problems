#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <vector <string>> vv(n); string s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> s;
			vv[i].push_back(s);
		}
		sort(vv[i].begin(), vv[i].end());
	}
	vector <int> prdk; int in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		prdk.push_back(in);
	}
	vector <string> ans;
	ans.push_back(vv[prdk[0] - 1][0]);
	for (int i = 1; i < n; i++) {
		int line = prdk[i]-1;
		for (int j = 0; j < 3; j++) {
			if (prev(ans.end())->compare(vv[line][j]) <= 0) {
				ans.push_back(vv[line][j]);
				break;
			}
			else if (j == 2) {
				cout << "IMPOSSIBLE";
				return 0;
			}
		}
	}
	for (auto ia : ans) {
		cout << ia << '\n';
	}
}