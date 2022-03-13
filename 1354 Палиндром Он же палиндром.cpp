#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	string vv; int m, l, r, rzm;
	cin >> vv;
		rzm = vv.size();
		if (rzm == 1) {
			cout << vv << vv;
			return 0;
		}
		for (m = rzm / 2; m < rzm; m++) {
			if (!(m == rzm / 2 && rzm % 2)) {
				for (l = m - 1, r = m; r < rzm && vv[l] == vv[r]; r++, l--) {
					if (r == rzm - 1 && rzm != 2 * m) {
						for (int i = 0; i < m; i++)
							_fputchar(vv[i]);
						for (int i = m - 1; i >= 0; i--)
							_fputchar(vv[i]);
						return 0;
					}
				}
			}
			for (l = m - 1, r = m + 1; r < rzm && vv[l] == vv[r]; r++, l--) {
				if (r == rzm - 1 && rzm != 2 * m + 1) {
					for (int i = 0; i <= m; i++)
						_fputchar(vv[i]);
					for (int i = m - 1; i >= 0; i--)
						_fputchar(vv[i]);
					return 0;
				}
			}
		}
		cout << vv;
		for (int i = rzm - 2; i >= 0; i--) {
			_fputchar(vv[i]);
		}
}