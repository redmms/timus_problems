#include <iostream>
#include <math.h>

using namespace std;
long double In; 
long double mOut[262144];
int i;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif
	
	while (cin>>In) {
		mOut[i]=sqrt(In);
		i++;
	}
	cout.setf(ios::fixed);	
	for ( i--;i>=0;i--){
			cout.precision(4);
			cout<<mOut[i]<<'\n';
	}
	
}