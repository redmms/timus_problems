#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> vec (n);
	int Kol3 = 0, Kol4 = 0, Kol5 = 0, v; float Sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		Sum += v = vec[i];
		if (v == 3)
			Kol3++;
		if (v == 4)
			Kol4++;
		if (v == 5)
			Kol5++;
	}
	if (Kol3 > 0)
		cout << "None";
	else if (Kol5 == n)
		cout << "Named";
	else if (Sum / n >= 4.5)
		cout << "High";
	else
		cout << "Common";
}