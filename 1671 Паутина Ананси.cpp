#include <iostream>
#include <vector>
using namespace std;
int parent[100001]; int SIZE[100001];
vector <bool> without(100001); vector <int> ansv(1);
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
	parent[v] = v;
	SIZE[v] = 1;
}

int union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (SIZE[a] < SIZE[b])
			swap(a, b);
		parent[b] = a;
		SIZE[a] += SIZE[b];
		return 1;
	}
	else
		return 0;
}
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	int n, m, q,
		l, r,
		ans, found;
	cin >> n >> m;
	vector <pair <int, int>> vv(m+1);
	for (int i = 1; i <= m; i++) 
		cin >> vv[i].first >> vv[i].second;
	cin >> q;
	vector <int> del(q+1);
	for (int i = 1; i <= q; i++) {
		cin >> del[i];
		without[del[i]] = true;
	}
	for (int i = 1; i <= n; i++) 
		make_set(i);
	ans = n;
	for (int i = 1; i <= m; i++) 
		if (!without[i]) 
			ans -= union_sets(vv[i].first, vv[i].second);
	ansv.push_back(ans);
	for (int i = q; i > 1; i--) {
		ans -= union_sets(vv[del[i]].first, vv[del[i]].second);
		ansv.push_back(ans);
		without[del[i]] = false;
	}
	for (int i = q; i >= 1; i--) 
		cout << ansv[i] << ' ';
}