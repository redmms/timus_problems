#include <iostream>
#include <string>
int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output2.txt", "wt", stdout);
    #endif
	using namespace std;
    int OY, OX, i, i2, y, x, n, AnsN;
	string s;
    cin >> n;
	OY=OX=8;
	for (i2=0; i2<n; i2++){
		cin >> s;
		x = s[0] - 'a' + 1;
		y = s[1] - '0';
		int mx[8]={x-2, x-2, x-1, x-1, x+1, x+1, x+2, x+2};
	    int my[8]={y-1, y+1, y-2, y+2, y-2, y+2, y-1, y+1};
 	    AnsN=0;
		for (i=0; i<8; i++){
			if(OX >= mx[i] && mx[i] > 0 && OY >= my[i] && my[i] > 0){
				AnsN++;
			}
		}
		cout << AnsN << '\n';
	}
	
}