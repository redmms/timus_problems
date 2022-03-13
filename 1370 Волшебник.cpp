#include <iostream>
#include <vector>
using namespace std;
int main() {
	long int n, m;
	cin >> n >> m;
	m = m%n;
	vector <int> list(n);
	for (int i = n-m; i < n; i++) {
		cin >> list[i];
	}
	for (long int i = 0; m+i-1<=n; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << list[i];
	}
}