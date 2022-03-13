#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;

	int counts, MaxCounts = 0; char MaxSymb;
	for (int i = 'A'; i <= 'z'; i++) {
		counts =count(s.begin(), s.end(), i);
		if (counts > MaxCounts) {
			MaxCounts = counts;
			MaxSymb = i;
		}
	}
	cout << MaxSymb;
}