#include <iostream>
using namespace std;
int main() {
	int T1, T2, a;
	cin >> T1 >> T2;

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		sum += a;
	}
	T2 -= sum * 20;
	
	if (T1 <= T2)
		cout << "No chance.";
	else
		cout << "Dirty debug :(";
}