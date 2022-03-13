#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	map <string, queue <string>> ans;
	string name, fac;
	for (int i = 0; i < n; i++) {
		getline(cin, name);
		getline(cin, fac);
		ans[fac].push(name);
	}
	for (char const *f : { "Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw" }) {
		cout << f << ':' << '\n';
		while (!ans[f].empty()) {
			string s = ans[f].front();
			ans[f].pop();
			cout << s << '\n';
		}
		cout << '\n';
	}
}