#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
	long int n; map <int, long int> KolDel;
	cin >> n;
	if (n == 0) {
		cout << 10;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 9; i >= 2; i--) {
		if (n%i == 0) {
			n = n / i;
			KolDel[i]++;
			i++;
		}
		if (n == 1)
			break;
	}
	if (KolDel.size() == 0 || n != 1)
		cout << -1;
	else {
		for (int i = 2; i <= 9; i++) {
			if (KolDel[i] > 0) {
				cout << i;
				KolDel[i]--;
				i--;
			}
		}
	}
}