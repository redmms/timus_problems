#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str1, str2;

int main() {
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int ans = 0;
	while (!str1.empty() || !str2.empty()) {
		if (!str1.empty() && !str2.empty()) {
			char b1 = str1.back();
			char b2 = str2.back();
			if (b1 == 'L' && b2 == 'L') str1.erase(str1.size() - 1, 1), str2.erase(str2.size() - 1, 1);
			else if (b1 == 'L') str2.erase(str2.size() - 1, 1);
			else if (b2 == 'L') str1.erase(str1.size() - 1, 1);
			else str1.erase(str1.size() - 1, 1), str2.erase(str2.size() - 1, 1);
		}
		else if (str1.empty()) str2.erase(str2.size() - 1, 1);
		else str1.erase(str1.size() - 1, 1);
		++ans;
		//cout << str1 << ' ' <<str2 << ' ' << ans << endl;
	}
	cout << ans << endl;
}