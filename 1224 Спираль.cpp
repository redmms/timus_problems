#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long n, m, a;
	cin >> n >> m;
	cout << min(2 * (n - 1), 2 * m - 1);
}