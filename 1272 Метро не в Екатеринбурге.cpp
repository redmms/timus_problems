#include <iostream>
#include <vector>
using namespace std;
vector <int> parent(12001); vector <int> SIZE(12001); vector <bool> wrote(12001);
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
	parent[v] = v;
	SIZE[v] = 1;
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (SIZE[a] < SIZE[b])
			swap(a, b);
		parent[b] = a;
		SIZE[a] += SIZE[b];
	}
}
int main() {
	int n, k, m,
		l, r,
		ans = 0, ingraph = 0, found;
	cin >> n >> k >> m;
	for (int i = 0; i < k; i++) {
		cin >> l >> r;
		if (!wrote[l])
			make_set(l);
		if (!wrote[r])
			make_set(r);
		union_sets(l, r);
		wrote[l] = wrote[r] = true;
	}
	vector <int> copy = parent;
	for (int i = 1; i <= n; i++) {
		if (wrote[i]) {
			if ((found = find_set(i)) == i) {
				ans++;
				ingraph += SIZE[found];
			}
		}
	}
	copy = parent;
	vector <int> s2 = SIZE;
	cout << (n - ingraph) + (ans - 1);
}