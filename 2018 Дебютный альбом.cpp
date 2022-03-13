#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int myfunction(int x, int y) { return (x + y) % 1000000007; }
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	int n, a, b, sa, sb;
	cin >> n >> a >> b;
	vector <vector <int> > sq(2, vector <int> (n + 1));
	sq[0][0] = sq[0][1] = sq[1][0] = sq[1][1] = 1;
	auto sma = [&](int & sa, int i, int j, int & a) {
		sa = sa - sq[j][i - a] + sq[j][i];
		if (sa < 0)
			sa += 1000000007;
		else if (sa >= 1000000007)
			sa -= 1000000007;
		return sa;
	};
	for (int i = 2; i <= n; i++) {
		if (i == a + 1)
			sa = accumulate(sq[1].begin(), sq[1].begin() + a, 0, myfunction);
		if (i == b + 1)
			sb = accumulate(sq[0].begin(), sq[0].begin() + b, 0, myfunction);
		sq[0][i] = (a == 1 ? sq[1][i - 1] : (i > a ?  sma(sa, i-1, 1, a): sq[0][i-1] + sq[1][i-1])) % 1000000007;
		sq[1][i] = (b == 1 ? sq[0][i - 1] : (i > b ?  sma(sb, i-1, 0, b): sq[0][i-1] + sq[1][i-1])) % 1000000007;
	}
	cout << (sq[0][n]+sq[1][n]) % 1000000007;
}