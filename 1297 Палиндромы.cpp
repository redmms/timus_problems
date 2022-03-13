#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> d1(n);
	int l = 0, r = -1;
	for (int i = 0; i<n; ++i) {
		int k = i>r ? 1 : min(d1[l + r - i], r - i + 1);
		while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])  ++k;
		d1[i] = k;
		if (i + k - 1 > r)
			l = i - k + 1, r = i + k - 1;
	}
	vector<int> d2(n);
	l = 0, r = -1;
	for (int i = 0; i<n; ++i) {
		int k = i>r ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])  ++k;
		d2[i] = k;
		if (i + k - 1 > r)
			l = i - k, r = i + k - 1;
	}
	int MAX = -1, im, d = 0, i;
	for (i = 0; i < n; i++)
		if (d1[i] > MAX) {
			MAX = d1[i]; im = i; d = 1;
		}
	for (i = 0; i < n; i++)
		if (d2[i] > MAX || (d == 1 && d2[i] == MAX)) {
			MAX = d2[i]; im = i; d = 2;
		}
	int firsti;
	if (d == 1)
		for (firsti = im - (MAX - 1), MAX = firsti + MAX * 2 - 2; firsti <= MAX; firsti++)
			cout << s[firsti];
	if (d == 2)
		for (firsti = im - MAX, MAX = firsti + 2 * MAX - 1; firsti <= MAX; firsti++)
			cout << s[firsti];
}