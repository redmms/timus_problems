#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <vector <int>> table(n, vector <int>(n));
	int i, j, i2, j2, c = 1, It, Numb = 1, l;
	for (j = n - 1; j >= 0; j--) {
		i = 0;
		j2 = j;
		for (It = 0; It < c; It++) {
			table[i][j2] = Numb;
			Numb++;
			i++; j2++;
		}
		if (c == n)
			break;
		c++;
	}
	c--;
	for (i = 1; i < n; i++) {
		j = 0;
		i2 = i;
		for (It = c; It > 0; It--) {
			table[i2][j] = Numb;
			Numb++;
			i2++; j++;
		}
		if (c == 0)
			break;
		c--;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << table[i][j]<< " ";
		}
		cout << '\n';
	}
}