#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<long, int> factorize(long x) {
	map<long, int> factors;
	for (int i = 2; i <= sqrt(x); i++) {
		while (x % i == 0) {
			factors[i]++;
			x /= i;
		}
	}
	if (x != 1) {
		factors[x]++;
	}
	return factors;
}
int del(vector <long> & vec, long sel) {
	long koldel = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] % sel == 0)
			koldel++;
	}
	return koldel;
}
int main() {
	long n;
	cin >> n;
	vector <long> t; 
	long kol1 = 0, kolvzsim = 0;
	for (long i = 0; i < n; i++) {
		long vv;
		cin >> vv;
		t.push_back(vv);
		if (vv == 1) {
			kol1++;
			kolvzsim++;
		}
		else {
			map <long, int> factors = factorize(vv);
			bool vzs = true;
			for (auto factor : factors) {
				long koldel = del(t, factor.first);
				if (koldel >= 3) {
					cout << "infinity";
					return 0;
				}
				if (koldel != 1) {
					vzs = false;
				}
			}
			if (vzs)
				kolvzsim++;
		}
	}
	if (kol1 == n) {
		cout << 0;
	}
	else if (kolvzsim == n) {
		cout << 1;
	}
	else
		cout << 2;
}








