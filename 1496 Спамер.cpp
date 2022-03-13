#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector <string> list(N);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < N-1; ) {
		string Comp = list[i];
		int KolCompEl = 0;
		for (int i1 = i; i1 < N; i1++) {
			if (list[i1] == Comp) {
				i++; KolCompEl++;
			}
		}
		if (KolCompEl > 1)
			cout << Comp << '\n';
	}
}