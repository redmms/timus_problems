#include <iostream>
#include <string>
using namespace std;
int main() {
	int hun = 2, sat = 10, n;
	cin >> n;
	string s;
	for (int i = 0, num; i < n; i++) {
		cin >> num >> s;
		if (s == "hungry")
			if (num > hun)
				hun = num;
		if (s == "satisfied")
			if (num < sat)
				sat = num;
	}
	if (hun >= sat)
		cout << "Inconsistent";
	else
		cout << sat;
}