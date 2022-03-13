#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	cout << max(0, max(n - k - 2, k - 3)) << endl;
}