#include <iostream>
#include <math.h>
using namespace std;
int main() {
	float k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	cout << round(1000 * k1 / (1 + k1 / k2 + k1 / k3));
}