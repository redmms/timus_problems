#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	multiset <long long> vv, dif;
	long long x;
	while(cin>>x)
		vv.emplace(x);
	dif.emplace(*next(vv.begin(), 1) - *vv.begin()); dif.emplace(*next(vv.begin(), 2) - *next(vv.begin(), 1));
	long long MIN = *min_element(dif.begin(), dif.end()); long long ans = 1;
	do {
		auto here = vv.emplace(MIN);
		if (here != vv.end()) dif.emplace(*next(here, 1) - MIN);
		if (here != vv.begin()) dif.emplace(MIN - *next(here, -1));
		MIN = *min_element(dif.begin(), dif.end());
		ans++;
	} while (MIN > 0);
	cout << ans;
}