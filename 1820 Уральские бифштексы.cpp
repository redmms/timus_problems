#include <iostream>

using namespace std;

int main() {
	int n, k, sum;
		
	cin >> n >> k;
	if (n <= k)
		sum = 2;
	else if((2 * n) % k >= 1)
		sum = ((2 * n) / k) + 1;
	else 
		sum = (2 * n) / k;
	cout << sum;
}