#include <iostream> 
using namespace std;
int main(){
	int m, i, n, a[100005][2], k, b[1005];
	cin >> n >> m;
	for (i = 0; i<m; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	for (i = 0; i<n; i++) {
		cin >> k;
		b[k] = i;
	}
	for (i = 0; i<m; i++) {
		if (b[a[i][0]]>b[a[i][1]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}