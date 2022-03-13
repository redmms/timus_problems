#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int m, vvod; vector <int> inp;
	cin >> m;
	for (;;) {
		cin >> vvod;
		if (vvod == -1)
			break;
		inp.push_back(vvod);
	}
	for (int i = 0; i < inp.size()-m+1; i++) {
		int MAX = inp[i];
		for (int i1 = 1; i1 < m; i1++)
			MAX = max(MAX, inp[i + i1]);
		cout << MAX << '\n';
	}
}