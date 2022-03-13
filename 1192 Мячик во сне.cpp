#include <iostream>
using namespace std;
int main() {
	int v, a; double k;
	cin >> v >> a >> k;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << ((v*v*k*sin(a*3.1415926535 / 90)) / (10 * (k - 1)));
}