#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int left = 0, right = 16, i = 1; long long a, ost = 0; string s, subs;
	cin >> s;
	s = string(17 - s.size() % 17, '0') + s;
	int len = s.length();
	int shagi = ceil(float(len) / 17);
	while (i <= shagi) {
		subs = s.substr(left, 17);
		const char * uk = subs.c_str();
		ost = (atoll(uk) % 7 + (ost*int64_t(1e17)) % 7);
		left += 17; i++;
	}
	ost %= 7;
	cout << ost;
}