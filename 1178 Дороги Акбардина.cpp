# include <iostream>
using namespace std;
int main()
{
	int n, i, j, k;
	int x[10002], y[10002], h[10002];
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		h[i] = i;
	}
	for (i = 1; i<n; i++)
		for (j = i + 1; j <= n; j++)
		{
			if ((x[j]<x[i]) || (x[j] == x[i] && y[j]>y[i]))
			{
				k = x[i]; x[i] = x[j]; x[j] = k;
				k = y[i]; y[i] = y[j]; y[j] = k;
				k = h[i]; h[i] = h[j]; h[j] = k;
			}
		}
	for (i = 1; i <= n; i += 2)
		cout << h[i] << " " << h[i + 1] << endl;
	return 0;
}