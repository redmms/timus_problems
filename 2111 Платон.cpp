#include <iostream>
using namespace std;

int main() {
	long long int n, sum = 0, d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d;
		sum += d;
	}
	cout << sum*sum;
}