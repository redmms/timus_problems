#include <iostream>
#include <vector>
using namespace std;
vector <vector <vector <int>>> g(1001, vector <vector <int>> (2)); vector<bool> used (1001);

void dfs(int v, int gi) {
		used[v] = true;
		for (vector<int>::iterator i = g[v][gi].begin(); i != g[v][gi].end(); ++i)
			if (!used[*i])
				dfs(*i, gi);

}
int main() {
	int n, l, r;
	cin >> n;
	for (;;) {
		if (!(cin >> l >> r)) {
			cin.clear();
			cin.ignore(6, 'D');
			break;
		}
		g[l][0].push_back(r);
		g[r][1].push_back(l);
	}
	while (cin >> l) {
		dfs(l, 0);
		dfs(l, 1);
	}
	bool notfound = true;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cout << i << ' ';
			notfound = false;
		}
	}
	if (notfound)
		cout << 0;
}