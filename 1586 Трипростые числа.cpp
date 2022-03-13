#include <iostream>
#include <vector>

using namespace std;

const uint64_t MOD = 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	uint64_t n; cin >> n;
	vector <bool> prime(1000, true);
	for (size_t i = 2; i < prime.size(); i++)
		for (size_t j = i * i; j < prime.size(); j += i)
			prime[j] = false;
	vector <uint64_t> primes;
	for (size_t i = 100; i < prime.size(); i++)
		if (prime[i])
			primes.push_back(i);
	vector < vector <uint64_t> > dp(n - 2, vector <uint64_t>(primes.size(), 0));
	vector < vector <size_t> > ind(100);
	for (size_t i = 0; i < primes.size(); i++) {
		ind[primes[i] % 100].push_back(i);
	}
	for (size_t i = 0; i < dp[0].size(); i++) dp[0][i] = 1;
	for (size_t i = 1; i < dp.size(); i++)
		for (size_t j = 0; j < dp[i].size(); j++)
			if (primes[j] / 10 > 9)
				for (auto& k : ind[primes[j] / 10]) {
					dp[i][j] += dp[i - 1][k];
					dp[i][j] %= MOD;
				}
	uint64_t ans = 0;
	for (size_t i = 0; i < dp.back().size(); i++)
		ans = (ans + dp.back()[i]) % MOD;
	cout << ans;
}