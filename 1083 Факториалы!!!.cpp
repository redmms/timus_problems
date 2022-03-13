#include <iostream>
#include <string>
using namespace std;
long long fact(int n, int k) {
	long long fact = 0, ans = 1; int i = 0;
	for (; n - i*k > 0; i++) {
		ans *= n - i*k;
	}
	return ans;
}
int main() {
	int n, k; string s;
	cin >> n >> s;
	k = s.length();
	cout << fact(n, k);
}