#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	long long vv[2][3]; bool pos;
	for (int i = 0; i<2; i++)
		for (int j = 0; j<3; j++)
			cin >> vv[i][j];
	long long dif = vv[0][0] - vv[1][0];
	vv[0][0] = max(dif, long long (0));
	vv[0][2] += min(dif, long long (0));
	dif = vv[0][1] - vv[1][1];
	vv[0][1] = max(dif, long long (0));
	vv[0][2] += min(dif, long long (0));
	if (vv[0][2]<0)
		pos = false;
	else
	{
		long long sum = vv[0][0] + vv[0][1] + vv[0][2];
		vv[0][2] = sum - vv[1][2];
		if (vv[0][2]<0)
			pos = false;
		else
			pos = true;
	}
	if (pos)
		cout << "It is a kind of magic";
	else
		cout << "There are no miracles in life";
}