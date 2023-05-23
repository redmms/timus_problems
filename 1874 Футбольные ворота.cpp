#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	cout << fixed << setprecision(6) << (a * a + b * b) / 4 + sqrt(2) * a * b / 2;
}