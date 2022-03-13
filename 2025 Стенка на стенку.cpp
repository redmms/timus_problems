#include <iostream>
#include <vector>
using namespace std;
int main() {
	int T, n, k;
	cin >> T;
	for (int i1 = 0; i1 < T; i1++) {
		cin >> n >> k;
		if (n == k)
			cout << n*(n - 1) / 2 << '\n';
		else {
			int ans = 0;
			vector <int> vec;
			for (int i = 0; i < n%k; i++)
				vec.push_back(n / k + 1);
			for (int i = 0; i < k - n%k; i++)
				vec.push_back(n / k);
			for (int left = 0; left < k; left++)
				for (int right = left+1; right < k; right++)
					ans += vec[left] * vec[right];
			cout << ans << '\n';
		}
	}
}