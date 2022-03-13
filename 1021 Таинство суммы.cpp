#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	int n1, n2, vv;	set <int> v1;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> vv;
		v1.insert(vv);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> vv;
		if (v1.find(10000 - vv) != v1.end()) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}