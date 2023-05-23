#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n, x, y, sqrSum, maxSqrSum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		sqrSum = x * x + y * y;
		if (sqrSum > maxSqrSum)
			maxSqrSum = sqrSum;
	}
	cout << "0 0 " << fixed << setprecision(9) << sqrt(maxSqrSum);
}