#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	 int n;
	cin >> n;
	
	 vector <long long> PrList(n);
	for (int i = 0; i < n; i++) {
		cin >> PrList[i];
	}

	cin >> n;
	 long long St; int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> St;
		if (binary_search(PrList.begin(), PrList.end(), St))
			sum++;
	}

	cout << sum;
}