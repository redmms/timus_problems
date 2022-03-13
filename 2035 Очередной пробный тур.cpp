#include <iostream>
using namespace std;
int main() {
	long x, y, c, a, b, MIN, MAX;
	cin >> x >> y >> c;
	if (x + y < c) {
		cout << "Impossible";
		return 0;
	}
	if (x >= c)
		cout << c << " " << 0;
	else if (y >= c)
		cout << 0 << " " << c;
	else{
		if (x < y)
			cout << x << " " << c - x;
		else 
			cout << c - y <<  " " << y ;
	}
}