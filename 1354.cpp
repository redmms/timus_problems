#include <iostream>
using namespace std;
string s; short Size;
inline bool checkSym(short l, short r) {
	for (; r < Size; l--, r++) 
		if (s[l] != s[r])
			return false;
	return true;
}
int main() {
	// We go from the center to the right side, because we can't attach a string to the left, and for every middle position wich is stored
	// at the same time in 'l' and 'r' for combining even and odd palindromes in one cycle, we check symmetry with checkSym() by a simple bruteforce, 
	// wich also goes from the center to palindromes sides (could also go from sides to the center, but we should find the longest one), and that's 
	// how we know if it's a palindrome. Note that distance between 'l' and 'r' is either 1 for even palindromes or 2 for odd
	cin >> s;
	Size = s.size();
	short l = (Size - 1) / 2, r = Size / 2 + 1;
	bool notBroken = true;
	if (Size < 3) {
		cout << s << s[0];
		return 0;
	}
	if (Size % 2) {  // start position is different for even and odd palindromes, so one extra check for even ones is needed
		if (checkSym(l, r))
			notBroken = false;
		r++;
	}
	if (notBroken)
		while (r < Size) {  // combined odd and even palindromes check
			if (checkSym(l, r))  // odd palindromes, distance between 'l' and 'r' == 2
				break;
			l++;
			if (checkSym(l, r))  // even palindromes, distance == 1
				break;
			r++;
		}
	for (short i = 0; i < r; i++)
		cout << s[i];
	for (short i = l; i > -1; i--)
		cout << s[i];
}
