
#include <iostream>
#include <string>
using namespace std;
int main() {
	int n; string arr[4] = { "16", "06", "68", "88" };
	cin >> n;
	if (n <= 4)
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	else
		cout << "Glupenky Pierre";
}