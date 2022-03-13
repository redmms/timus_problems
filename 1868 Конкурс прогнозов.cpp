#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
cin.tie(0);
	map <string, string> com; string vv; char l[50], r[50]; int n, n2, kol; vector <int> kolst;
	for (int i = 1; i <= 4; i++) {
		cin >> vv;
		com[vv] = "gold";
	}
	for (int i = 5; i <= 8; i++) {
		cin >> vv;
		com[vv] = "silver";
	}
	for (int i = 9; i <= 12; i++) {
		cin >> vv;
		com[vv] = "bronze";
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n2;
		kol = 0;
		for (int j = 0; j < n2; j++) {
			scanf("%s : %s", l, r);
			if (com[l] == r)
				kol++;
		}
		kolst.push_back(kol);
	}
	int MAX = 0, kolm = 0;
	for (int i = 0; i < n; i++) {
		if (kolst[i] > MAX) {
			MAX = kolst[i];
			kolm = 1;
		}
		else if (kolst[i] == MAX) {
			kolm++;
		}
	}
	cout << kolm * 5;

}