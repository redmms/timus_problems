#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, vv, mx, ans = 0, pri; 
	cin >> n;
	vector <int> kolsr(n);
	cin >> vv;
	mx = vv;
	pri = 0;
	for (int i = 1; i < n; i++) {
		cin >> vv;
		if (vv < mx) {
			pri = i;
			mx = vv;
			kolsr[pri]++;
		}
		else
			kolsr[pri]++;
	}
	cout << max_element(kolsr.begin(), kolsr.end())-kolsr.begin()+1;
}