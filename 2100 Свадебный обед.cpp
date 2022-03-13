#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s;

	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.find("+one") != string::npos) {
			ans += 2;
		}
		else
			ans++;
	}
	ans += 2;
	if (ans != 13)
		cout << ans * 100;
	else
		cout << 1400;
}