#include <iostream>
using namespace std;
int main() {
	int rec, MIN, ans = 0; double prom; float pr;
	cin >> rec >> MIN >> pr;
	pr = (100 - pr) / 100;
	for (prom = rec; prom > MIN; ans++, prom *= pr){
	}
	cout << ans;
}