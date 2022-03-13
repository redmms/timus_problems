#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int h, w, n; string s;
	cin >> h >> w >> n;
	int OstDlStr = w, KolvoStrok = 1, KolvoStranits = 1;
	for (int i = 0; i < n; i++) {
		cin >> s;		
		int Len = s.length();
		if (KolvoStrok == h && Len > OstDlStr) {
			KolvoStranits++;
			KolvoStrok = 0;
		}
		if (Len <= OstDlStr)
			OstDlStr -= Len+1;
		else {
			KolvoStrok++;
			OstDlStr = w - Len - 1;
		}		
	}
	cout << KolvoStranits;
}