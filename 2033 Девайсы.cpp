#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
	map <string, int> dev; map <string, int> kol; string tel, fuck; long int cena;
	for (int i = 0; i < 6; i++) {
		cin >> fuck >> tel >> cena;
		if (dev[tel] > cena || dev[tel] == 0) {
			dev[tel] = cena;
			kol[tel]++;
		}
		else
			kol[tel]++;
	}
	int maxKol = 0; string maxS;
	for (auto &it : kol) {
		if (it.second > maxKol ){
			maxKol = it.second;
			maxS = it.first;
		}
	}
	for (auto &it : kol) {
		if (it.second == maxKol && dev[it.first] < dev[maxS]) {
			maxKol = it.second;
			maxS = it.first;
		}
	}
	cout << maxS;
}