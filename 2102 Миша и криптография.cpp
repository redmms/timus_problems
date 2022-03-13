#include <iostream>
using namespace std;
int factorize(long long x) {
	int sum = 0;
	for (int i = 2; i <= 10000000; i++) {
			while (x % i == 0 && sum <= 21) {
				sum++;
				x /= i;
			}
	}
	if (x != 1) {
		sum++;
	}
	return sum;
}
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	long long n;
	cin >> n;
	if (factorize(n) == 20)
		cout << "Yes";
	else
		cout << "No";
}