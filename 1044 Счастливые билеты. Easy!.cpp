#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n, sum, copy, subleng; long long ans = 0;
	cin >> n;
	int leng = n / 2, maxs = leng * 9; string s(leng, '9'); int maxn = stoi(s);
	vector <int> v(maxs + 1);
	for (int chislo = 0; chislo <= maxn; chislo++) {
		sum = 0;
		copy = chislo;
		for (int step = 1; step <= leng; step++) {
			sum += copy % 10;
			copy /= 10;
		}
		v[sum]++;
	}
	for (int i = 0; i < maxs + 1; i++) {
		ans += v[i] * v[i];
	}
	cout << ans;
}