#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	double x, y, r, x1, y1, xPr, yPr, a, b, Summ = 0;

	cin >> n >> r;
	cin >> x1 >> y1;
	xPr = x1; yPr = y1;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		a = x - xPr;
		b = y - yPr;
		xPr = x;
		yPr = y;
		Summ += sqrt(a*a + b*b);
		if (i == n - 2) {
			a = x - x1;
			b = y - y1;
			Summ += sqrt(a*a + b*b);
		}
	}
	Summ += 2 * M_PI*r;

	cout.precision(2);
	cout.setf(ios::fixed);
	cout << Summ;
}