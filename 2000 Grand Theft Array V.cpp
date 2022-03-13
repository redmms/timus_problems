#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std; 
int sum(vector <int> & v, int l, int r){
	int s = 0;
	for (int i = l; i <= r; i++) {
		s += v[i];
	}
	return s;
}
int main() {
	int n, x, y, l, r, sx, sy, sl, sr;
	cin >> n;
	vector <int> ish(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> ish[i];
	cin >> x >> y;
	if (x > y) {
		l = y; r = x;
	}
	else {
		l = x; r = y;
	}
	sl = sum(ish, 1, l-1), sr = sum(ish, r+1, n);
	if (x == y) {
		sx = max(sl, sr)+ish[x];
		sy = min(sl, sr);
	}
	else if (x < y) {
		sx = sl + sum(ish, l, (l+r) / 2);
		sy = sr + sum(ish, (l + r) / 2 + 1, r);
	}
	else {
		int ost = (l + r) % 2;
		sx = sr + sum(ish,  !ost ? (l + r) / 2 : (l+r)/2+1, r);
		sy = sl + sum(ish, l, !ost ? (l + r) / 2 - 1 : (l+r)/2);
	}
	cout << sx << ' ' << sy;
}