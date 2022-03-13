#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int ll1 = (unsigned long long) 1;
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	string vv; int n;
	cin >> n >> vv;

	bitset <100> o, mask10("1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"), mask01("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101");
	for (int i = 0; i < n*5-1; i++) {
		if (vv[i] == '>') {
			o <<= ll1;
			o |= ll1;
		}
		else if (vv[i] == '<') {
			o <<= ll1;
		}
	}
	bitset <100> l(o >> (n / 2)), r(o << (n / 2 + 100 - n));

	int Codd = (o^mask10).count() - (100 - n) / 2, Ceven = (o^mask01).count() - (100 - n) / 2, olC = l.count(), orC = r.count(), Cl = olC + n / 2 - orC, Cr = n / 2 - olC + orC;

	cout << min(min(min(Codd, Ceven), Cl), Cr);

}