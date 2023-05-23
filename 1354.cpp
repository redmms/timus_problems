#include <iostream>
using namespace std;
string s; short Size;
bool checkSym(short l, short r) {
	for (; r < Size; l--, r++) 
		if (s[l] != s[r])
			return false;
	return true;
}
int main() {
	cin >> s;
	Size = s.size();
	short l = (Size - 1) / 2, r = Size / 2 + 1;
	bool notBroken = true;
	if (Size < 3) {
		cout << s << s[0];
		return 0;
	}
	if (Size % 2) {
		if (checkSym(l, r))
			notBroken = false;
		r++;
	}
	if (notBroken)
		while (r < Size) {
			if (checkSym(l, r))
				break;
			l++;
			if (checkSym(l, r))
				break;
			r++;
		}
	for (short i = 0; i < r; i++)
		cout << s[i];
	for (short i = l; i > -1; i--)
		cout << s[i];
}