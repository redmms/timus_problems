#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int main() {
	string vv, left, right; bool rbigger = false;
	cin >> vv;
	int len = vv.length(), halfl = len / 2;
	if (len % 2 == 0) 
		left = vv.substr(0, halfl), right = vv.substr(halfl, halfl);
	else 
		left = vv.substr(0, halfl+1), right = vv.substr(halfl + 1, halfl);
	for (int i = 0; i < halfl; i++) {
		if (left[i] < right[halfl - 1 - i]) {
			rbigger = true;
			break;
		}
	}
	if (rbigger) {
		if (left[halfl - 1] > right[0]) 
			right[0] = left[halfl - 1];
		else {
			for (int i = round((float (vv.length()))/2) - 1; i >= 0; i--) {
				if (left[i] >= '9') {
					left[i] = '0';
				}
				else {
					left[i]++;
					break;
				}
			}
		}
	}
	cout << left;
	if (len % 2 != 0) left.pop_back();
	reverse(left.begin(), left.end());
	cout << left;
}