#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, maxs, s, i, ians=2;
	
	cin >>n;
	vector <int> vec(n);
	for (i=0; i<n;i++){
		cin>>vec[i];
	}
	maxs=vec[0]+vec[1]+vec[2];
	for (i=1;i<n-2; i++){
		s=vec[i]+vec[i+1]+vec[i+2];
		if (s>maxs){
			maxs=s;
			ians=i+2;
		}
	}
	cout<<maxs<<" "<<ians;
}
	