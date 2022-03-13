#include <iostream>
#include <string>
using namespace std;
bool check(char const* s) {
	while (*s != '\0') {
		if (!memcmp(s, "one", 3))
			s += 3;
		else  if (!memcmp(s, "puton", 5))
			s += 5;
		else  if (!memcmp(s, "outputone", 9))
			s += 9;
		else  if (!memcmp(s, "outputon", 8))
			s += 8;
		else  if (!memcmp(s, "output", 6))
			s += 6;
		else  if (!memcmp(s, "out", 3))
			s += 3;
		else  if (!memcmp(s, "inputone", 8))
			s += 8;
		else  if (!memcmp(s, "inputon", 7))
			s += 7;
		else  if (!memcmp(s, "input", 5))
			s += 5;
		else  if (!memcmp(s, "in", 2))
			s += 2;
		else
			return false;
	}
	return true;
}int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (check(&s[0]))
			printf("YES\n");
		else
			printf("NO\n");
	}
}