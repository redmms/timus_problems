#include <iostream>
#include <map>
using namespace std;
int main() {
	int n;
	cin >> n;

	map <int, int> m; int d, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> d;
		auto f = m.find(d);
		if ( f == m.end())
			m.insert(make_pair(d, 1));
        else {
			f->second++;
	    	if ((f->second+1) % 4 == 1)
                ans++;
        }
	}
	cout << ans;
}