#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int i,j,n,m,k;
	for(i=0;i<1000000;i++){
		k=rand()%26;
		k+=97;
		cout<<(char)k;
	}
		//cin.get();
		return 0;
}