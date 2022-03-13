#include <iostream>
using namespace std;
int main() {
	long int x, y;
	cin >> x >> y;
	if (x <= 0 || y <= 0)
		cout << x << ' ' << y;
	else if ((x + y) % 2 != 0)
		cout << y << ' ' << x;
	else
		cout << x << ' ' << y;
}