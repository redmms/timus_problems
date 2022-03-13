#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	if (n > 999)
		cout << "legion";
	else if (n > 499)
		cout << "zounds";
	else if (n > 249)
		cout << "swarm";
	else if (n > 99)
		cout << "throng";
	else if (n > 49)
		cout << "horde";
	else if (n > 19)
		cout << "lots";
	else if (n > 9)
		cout << "pack";
	else if (n > 4)
		cout << "several";
	else
		cout << "few";
}