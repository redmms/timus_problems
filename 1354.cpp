#include <iostream>
using namespace std;
int main() {
	// We go from the center to the right side, because we can't attach a string to the left, and for every middle position wich is stored
	// at the same time in 'l' and 'r' for composing even and odd palindromes in one cycle, we check symmetry with checkSym() by a simple bruteforce, 
	// wich also goes from the center to palindromes sides (could also go from sides to the center, but we should find the longest one), and that's 
	// how we know if it's a palindrome. Note that distance between 'l' and 'r' is either 1 for even palindromes or 2 for odd
	string s;
	cin >> s;
	short strsize = s.size(), l = strsize - 1 >> 1, r = (strsize >> 1) + 1;
	if (strsize < 3) {
		cout << s << s[0];
		return 0;
	}
	auto checkSym = [s, strsize](short l, short r) {
		for (; r < strsize; l--, r++)
			if (s[l] != s[r])
				return false;
		return true;
	};
	[&]() {
		if (strsize & true) {  // start position is different for even and odd palindromes, so one extra check for even ones is needed
			if (checkSym(l, r))
				return;
			r++;
		}
		while (r < strsize) {  // composed odd and even palindromes check
			if (checkSym(l, r))  // odd palindromes, distance between 'l' and 'r' == 2
				return;
			l++;
			if (checkSym(l, r))  // even palindromes, distance == 1
				return;
			r++;
		}
	}();
	for (short i = 0; i < r; i++)
		cout << s[i];
	for (short i = l; i > -1; i--)
		cout << s[i];
}