#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif	
	int n, i, ans;

	cin >> n;
	vector <string> names(n, string());
	ans = 0;
	getline(cin, names[0]);
	for (i = 0; i < n; i++) {
		getline(cin, names[i]);
	}
	for (i = 0; i < names.size(); i++) {
		for (int i2 = i + 1; i2 < names.size(); i2++) {
			if ((i != i2) && (names[i] == names[i2])) {
				ans++;
				names.erase(names.begin()+i2);
				i2--;
			}
		}
	}
	cout << ans;
}