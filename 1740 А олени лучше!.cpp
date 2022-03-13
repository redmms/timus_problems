#include <iostream>
using namespace std;
int main() {
	int l, k, h;
	cin >> l >> k >> h;
	cout << (l / k)*h << ".00000000 " << int(ceil(((double)l) / k))*h << ".00000000";
}