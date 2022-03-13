#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n; long int s;	int sum = 1;
	cin >> n >> s;
	vector <int> ans(n);
	vector <long int> d(n);
	for (int i = 0; i < n; i++) 
		cin >> d[i];
	for (int i = 0; i < n - 1; i++)
		sum *= ans[i + 1] = d[i] / d[i+1];
	ans[0] = s / sum;
	for (int i = 0; i < n; i++)
		cout << ans[i] - 1 << " ";
}