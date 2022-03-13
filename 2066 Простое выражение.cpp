#include <iostream>

using namespace std;

int main() {
	int a, b, c, ans;

	cin >> a >> b >> c;

	if (b*c > b + c)
		cout << a - b*c;
	else
		cout << a - b - c;
}