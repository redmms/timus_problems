#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	long int price;  long int sum = 0; map <long int, long int> nom = { {10, 0}, {50, 0}, {100, 0}, {500, 0}, {1000,0}, {5000, 0} };
	for (auto &it : nom) {
		cin >> it.second;
		sum += it.first*it.second;
	}
	cin >> price;
	long int min;
	for (auto &it : nom) {
		if (it.second > 0) {
			min = it.first;
			break;
		}
	}
	if (min <= price) {
		cout << 1 << '\n' << sum / price;
		return 0;
	}
	long int minsum = sum - min; long int prom;
	vector <long int> ans;
	for (prom = price*(minsum/price) + price; prom <= sum; prom += price) {
		ans.push_back(prom/price);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}