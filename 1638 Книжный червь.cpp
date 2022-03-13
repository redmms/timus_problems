#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, ans;
	cin >> a >> b >> c >> d;
	if (d >= c)
		ans = (d - c + 1)*(a + b * 2) - b * 2 - a * 2;
	else
		ans = (c - d + 1)*(a + b * 2) - b * 2;
	cout << ans;
}