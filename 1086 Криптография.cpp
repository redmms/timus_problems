#include <iostream> 
#include <vector> 
#include <iterator>
using namespace std;
int n = 163841;
vector<char> prime(n + 1, true);
void eratosphen() {
	prime[0] = false;
	prime[1] = false;
	for (int i1 = 2; i1 <= n; ++i1)
		if (prime[i1])
			if (i1 * 1ll * i1 <= n)
				for (int j1 = i1 * i1; j1 <= n; j1 += i1)
					prime[j1] = false;
}
int main() {
	eratosphen();
	vector <long long> list(15001); int i = 2;
	for (int il = 1; il <= 15000;) {
		for (int ip = 2; ip < prime.size(); ip++) {
			if (prime[ip]) {
				list[il] = ip;
				il++;
			}
		}
	}
	int k;
	cin >> k;
	for (int i0 = 0; i0 < k; i0++){
		int m;
		cin >> m;
		cout << list[m] << '\n'; \
	}
}