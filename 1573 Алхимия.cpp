#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	int b, r, y;
	cin >> b >> r >> y;
	int k;
	cin >> k;
	map <string, int> colors; string color;
	for (int i = 1; i <= k; i++) {
		cin >> color;
		if (color == "Red")
			colors["Red"] = r;
		else if (color == "Blue")
			colors["Blue"] = b;
		else if (color == "Yellow")
			colors["Yellow"] = y;
	}
	int ans = 1;
	for (auto it : colors) {
		ans *= it.second;
	}
	cout << ans;
}