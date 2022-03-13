#include <iostream>
#include <string>

using namespace std;

int main(){
		char table[11][4]={".,!", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz", " "}; string s; int sum =0;
		 getline(cin,s);
		for (int i = 0; i<11; i++){
			for (int j =0; j<3 && table[i][j]!=0; j++){
				for(char &c:s)
				if(table[i][j]==c){
				sum+=j+1;
				c='*';
				}
			}
		}
		cout<<sum;
}
				