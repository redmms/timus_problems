#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> ish(3001);
void goLnU(int oldroot, int oldLTroot) {
	if (oldroot == 0)
		return;
	int i; bool increasing = true; int length = 1;
	for (i = oldroot - 1; ish[i] > ish[oldroot]; i--) {
		length++;
		if (ish[i] < ish[i + 1])
			increasing = false;
	}
	int newLTroot = i;
	if (length == 1) {
		if (newLTroot != oldLTroot)
			goLnU(newLTroot, oldLTroot);
		cout << ish[oldroot] << '\n';
		return;
	}
	else if (increasing && newLTroot == oldLTroot) {
		for (int i = newLTroot + 1; i <= oldroot; i++) {
			cout << ish[i] << '\n';
		}
	}
	else if (newLTroot != oldLTroot) {
		goLnU(oldroot - 1, newLTroot);
		goLnU(newLTroot, oldLTroot);
		cout << ish[oldroot] << '\n';
	}
	else {
		goLnU(oldroot - 1, oldLTroot);
		cout << ish[oldroot] << '\n';
	}
}
int main() {
cin.sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ish[i];
	int rooti = n;
	goLnU(rooti, -1);
}