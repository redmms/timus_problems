
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;

		int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A')
			sum += s[i] - 'A' + 10;
		else
			sum += s[i] - '0';
	}

		char max = '0'; int Osn;
	for (int i = 0; s[i] != '\0'; i++) {
		if (max < s[i]) {
			max = s[i];
		}
	}
	if (max >= 'A')
		Osn = max - 'A' + 10 + 1;
	else
		Osn = max - '0' + 1;
	if (Osn < 2)
		Osn = 2;

	for (long long k = Osn; k <= 36; k++) {
		if (sum % (k - 1)==0) {
			cout << k;
			return 0;
		}
	}

	cout << "No solution.";
}