#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	long double const PI = acos(-1.); long double x, y; long long n, i, ic = 0, MIN = LLONG_MAX; set <pair<long double, long long>> ang; vector <vector <long long>> vv(2);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		vv[0].push_back(x); vv[1].push_back(y);
		if (x < MIN) {
			MIN = x;
			ic = i;
		}
	}
	for (long long i = 0; i < n; i++) {
		if (i != ic)
		ang.insert(make_pair(atan2(vv[1][i] - vv[1][ic], vv[0][i] -vv[0][ic]), i+1));
	}	
	cout << ic+1 << ' ' << next(ang.begin(), n/2-1)->second;
}