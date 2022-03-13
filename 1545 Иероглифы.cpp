#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	char FirstC;
	string support;

	cin >> n;
	vector <string> dic(n, string());
	for (int i = 0; i < n; i++) {
		cin >> dic[i];
	}
	cin >> FirstC;
	for (int i = 0; i < n; i++) {
		if (dic[i][0] == FirstC)
			cout << dic[i] << '\n';
	}
}