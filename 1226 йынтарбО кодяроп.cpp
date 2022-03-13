#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string c = "a";
	string word;
	for (;;) {
		c = getc(stdin);
		if (c[0] == EOF) {
			reverse(word.begin(), word.end());
			cout << word;
			break;
		}
		if (((c[0] >= 'a') && (c[0] <= 'z')) || ((c[0] >= 'A') && (c[0] <= 'Z'))) {
				word.append(c);
		}
		else {
			reverse(word.begin(), word.end());
			cout << word << c;
			word.clear();
		}
	}
}