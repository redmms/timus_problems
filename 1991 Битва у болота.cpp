#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
	int SvdB = 0, SrvvdS = 0;
	int n, k;

	cin >> n >> k;
	for (int i=0; i<n; i++){
		int a;
		cin >> a;
		int Dif = k-a;
		if (Dif > 0)
			SrvvdS += Dif;
		if (Dif < 0)
			SvdB += abs(Dif);
	}
	cout << SvdB << " " << SrvvdS;
}