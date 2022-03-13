#include <iostream>
using namespace std;
int main() {
	int N; long long a; long float sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		sum += a;
	}
	sum /= N;
	cout.precision(6);
	cout.setf(ios::fixed);
	cout << sum;
}