#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int main() {
	unsigned int inp, ans = 0; string side; vector <unsigned char> cifry(4); vector <unsigned int> s(4);
	cin >> side >> inp;
	for (int i = 3; i >= 0; i--) {
		s[i] = pow(256, i);
		cifry[i] = inp / s[i]; inp = inp % s[i];
	}
	reverse(cifry.begin(), cifry.end());
	for (int i = 3; i >= 0; i--) {
		ans += s[i] * cifry[i];
	}
	cout << ans;
}