#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
//#include <ctime>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif	
	int n, i;
	unsigned int k;
	vector <int> pos;
	vector <int> ent(65535, int());
	vector <int> ans(65535, int());
	//pos-positions
	//ent-enter
	//ans-answer
	k = 1;
	for (i = 1; k <= 2147483647; i++) {
		pos.push_back(k);
		k += i;
	}

	cin >> n;
	vector <int>::iterator b, e;
	b = pos.begin();
	e = pos.end();
	for (i = 0; i < n; i++) {
		cin >> ent[i];
		if (binary_search(b, e, ent[i]))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}

	//for (i = 0; i < n; i++) {
	//	cout << ans[i] << " ";
	//}
	//unsigned int end_time = clock();
	//cout << end_time;
}