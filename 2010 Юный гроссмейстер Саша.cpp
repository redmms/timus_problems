#include <iostream>
#include <stdio.h>
int min(int a, int b){
	if (a<b)
	return a;
	else 
	return b;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif
	using namespace std;
	int OX, OY, x, y, xX, yY, n, i, AnsN, AnsR, AnsB, AnsQ, AnsK;
	cin >> n >> x >> y;
	OX=OY=n;
	xX=OX-x;
	yY=OY-y;
	AnsN=AnsR=AnsB=AnsQ=AnsK=0;
	{
		int mx[8]={x-1, x-1, x-1, x, x, x+1, x+1, x+1};
		int my[8]={y-1, y, y+1, y-1, y+1, y-1, y, y+1};
		for (i=0; i<8; i++){
			if(OX >= mx[i] && mx[i] > 0 && OY >= my[i] && my[i] > 0){
				AnsK++;
			}
		}
		cout<<"King: "<<AnsK<<'\n';
	};
	{
		int mx[8]={x-2, x-2, x-1, x-1, x+1, x+1, x+2, x+2};
	    int my[8]={y-1, y+1, y-2, y+2, y-2, y+2, y-1, y+1};
		for (i=0; i<8; i++){
			if(OX >= mx[i] && mx[i] > 0 && OY >= my[i] && my[i] > 0){
				AnsN++;
			}
		}
		cout << "Knight: "<<AnsN << '\n';
	};	
		AnsB +=min(x, y) + min(xX+1, y) + min(yY+1, x) + min (yY, xX) -3;
		cout<<"Bishop: "<<AnsB<<'\n';
		AnsR=OX*2-2;
		cout<<"Rook: "<<AnsR<<'\n';
	    AnsQ=AnsR+AnsB;
	    cout<<"Queen: "<<AnsQ<<'\n';
}