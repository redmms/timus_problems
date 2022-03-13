#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n, n05, Ans=0;
	
	cin >> n;
	vector <int> groups(n, int());
	n05 = int(n / 2 + 1);
	for (int i = 0; i < n; i++) {
		cin >> groups[i];
	}
	for (int i = 0; i < n05; i++) {
		Ans += int((* min_element(groups.begin(), groups.end())) / 2) + 1;
		groups.erase(min_element(groups.begin(), groups.end()));
	}
	cout << Ans;
}