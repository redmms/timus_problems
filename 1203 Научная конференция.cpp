#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
bool sortbysec(const pair<int, int> &a,	const pair<int, int> &b) {
	return (a.second == b.second ? a.first < b.first : a.second < b.second);
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	list <pair <int, int>> dano(n);
	for (pair<int, int> &p : dano)
		cin >> p.first >> p.second;
	dano.sort(sortbysec);
	for (auto p = next(dano.begin()); p != dano.end();) {
		if (p->second == prev(p)->second)
			dano.erase(prev(p++));
		else if (p->first <= prev(p)->second)
			dano.erase(p++);
		else
			p++;
	}
	cout << dano.size();
}