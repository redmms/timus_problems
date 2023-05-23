#include <iostream>
#include <vector>
using namespace std;
int t[400000], n, k, soldId; vector <int> soldiers;
void build(vector <int> & a, int v, int tl, int tr) {
	if (tl == tr)
		t[v] = bool(a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[v] = (t[v * 2]) + (t[v * 2 + 1]);
	}
}
int sum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum(v * 2, tl, tm, l, min(r, tm))
		+ sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
} 
void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val; // можно убрать булевское преобразование так как на входе всегда будет 0
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}
int lastEl(int v, int tl, int tr) {
	if (tl == tr)
		return tl;
	int rm = (tl + tr) / 2 + 1;
	if (sum(v * 2 + 1, rm, tr, rm, tr)) {
		lastEl(v * 2 + 1, rm, tr);
	}
	else {
		lastEl(v * 2, tl, rm - 1);
	}
}
void move(int v, int tl, int tr, int l, int nD) {
	int m = (tl + tr) / 2, 
		nZtoEnd = sum(v, tl, tr, l, tr);
	if (nZtoEnd < nD) { // это возможно только при v == 1, либо когда осталось мало элементов
		int nZWhole = sum(1, 0, n, 0, n);
		nD = (nD - nZtoEnd) % nZWhole;
		if (nD)
			move(1, 0, n, 0, nD);
		else
			soldId = lastEl(1, 0, n);
	}
	else if (nZtoEnd == nD)
		soldId = lastEl(v, tl, tr); // если нашли нужную точку, выходим из рекурсии
	else if (l > m)
		move(v * 2 + 1, m + 1, tr, l, nD); // если l в правой половине отрезка, идем на правую половину
	else {
		int nZLeft = sum(v * 2, tl, m, l, m);
		if (nZLeft < nD)
			move(v * 2 + 1, m + 1, tr, m + 1, nD - nZLeft); // идем на правый подотрезок уменьшив значение дистанции на сумму от l до m, и изменив точку отсчета l на середину (m + 1)
		else
			move(v * 2, tl, m, l, nD); // если nD <= nZLeft идем на левый подотрезок
	}
}
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	int k;
	cin >> n >> k;
	soldiers.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		soldiers[i] = i;
	}
	build(soldiers, 1, 0, n);
	soldId = 0;
	for (int m = 0; m < n; m++) { // m - номер запроса
		move(1, 0, n, soldId, k);
		cout << soldiers[soldId] << " ";
		soldiers[soldId] = 0;
		update(1, 0, n, soldId, 0);
	}
}