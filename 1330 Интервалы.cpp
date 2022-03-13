#include <stdio.h>
#include <vector>
using namespace std;
vector <int> inp(10000), der(40000);
void build(int v, int vl, int vr, vector <int> &a) {
	if (vl == vr) {
		der[v] = a[vl];
		return;
	}
	int vm = vl + (vr - vl) / 2;
	build(2 * v + 1, vl, vm, a);
	build(2 * v + 2, vm + 1, vr, a);
	der[v] = der[2 * v + 1] + der[2 * v + 2];
}
int query(int v, int vl, int vr, int l, int r) {
	if (r < vl || vr < l)
		return 0;
	if (l <= vl &&vr <= r)
		return der[v];
	int vm = vl + (vr - vl) / 2;
	int ql = query(2 * v + 1, vl, vm, l, r);
	int qr = query(2 * v + 2, vm + 1, vr, l, r);
	return ql + qr;
}
int main() {
	int N, k, i, j; long int Q;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inp[i]);
	}
	scanf("%d", &Q);
	build(0, 0, N - 1, inp);
	for (long int i1 = 0; i1 < Q; i1++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", query(0, 0, N - 1, i -1, j-1));
	}
}