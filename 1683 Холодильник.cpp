#include <iostream> 
#include <cmath>
using namespace std;
int main() {
	double n;
	cin >> n;
	cout << (int)ceil(log(n) / log(2)) << '\n';
	while (n > 1) {
		n = ceil(n / 2);
		cout << (int)n << ' ';
	}
}