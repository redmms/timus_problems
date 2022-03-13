#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
        cin.sync_with_stdio(false); cin.tie(0);
	int n; vector <int> vv, vvc;
	while (cin >> n) {
		if (n)
			vv.push_back(n);
	}
	vvc = vv;
	int maxel = *max_element(vv.begin(), vv.end());
	vector <unsigned __int16> seq(maxel + 2); seq[0] = 0; seq[1] = 1;
	for (int i = 1; i <= maxel / 2; i++) {
		seq[i << 1] = seq[i];
		seq[i << 1 | 1] = seq[i] + seq[i + 1];
	}
	for (int i = 0; i < vvc.size(); i++)
		cout << *max_element(seq.begin(), seq.begin() + vvc[i] + 1) << '\n';
}