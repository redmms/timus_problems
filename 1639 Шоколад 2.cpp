#include <iostream>

using namespace std;

int main(){
	int m, n, vs=0;
	//vs-всего
	
	cin >> m >> n;

    if (n==1)
		vs=m-1;
	else if (m==1)
		vs=n-1;
       else
       	vs=n*m-1;

	
	if (vs%2==0)
		 cout<<"[second]=:]";
	 else
	 	 cout<<"[:=[first]";
	 
}