#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
		vector <vector <int>> st(3);
		st[0].push_back(2); st[1].push_back(3); st[2].push_back(4);
		for (int i = 0; i <= 2; i++) {
			int osn = i + 2;
			for (;;) {
				int newst = (osn * *--st[i].end()) % 100;
				if (!count(st[i].begin(), st[i].end(), newst))
					st[i].push_back(newst);
				else
					break;
			}
		}	
		int n;
		cin >> n;
		n--;
		int sum = 1 + st[0][n < 21 ? n : n  % 20 ] + st[1][n % 20] + st[2][n % 10];
		if (sum % 100 == 0)
			cout << 2;
		else if (sum % 10 == 0)
			cout << 1;
		else
			cout << 0;

}