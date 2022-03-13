#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool revs(int & a, int & b) {
	return a>b;
}
int main() {
	int n, k, s = 0, vv;
	cin >> n >> k;
	vector <int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> vv;
		a[i] = vv;
	}
	sort(a.begin(), a.end(), revs);
	int ost = a[0], d;
	for (int i = 1; i < k; i++) {
		d = n - ost;
		ost = a[i] - d;
		if (ost <= 0) {
			cout << 0;
			return 0;
		}
	}
	cout << ost;
}