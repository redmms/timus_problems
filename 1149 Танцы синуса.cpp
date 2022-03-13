#include <iostream>  
#include <string>
#include <sstream>
using namespace std;
string An(int N) {
	string s;
	s = to_string(N);
	for (int i = N; i >= 1; i--) {
		stringstream ss;
		if (i == 1){
			ss << "sin(" << s << ')';
		}
		else if (i % 2 == 0) {		
			ss << i - 1  << "-sin(" << s << ')';
		}
		else {
			ss << i - 1 << "+sin(" << s << ')';
			
		}
		s.clear();
		s = ss.str();
	}
	return s;
}
string Sn(int N) {
	string s;
	for (int i = N, i2 = 1; i >= 1; i--, i2++) {
		stringstream ss;
		if (i == N)
			ss << An(i2) << '+' << i;
		else
			ss << '(' << s << ')' << An(i2) << '+' << i;
		s.clear();
		s = ss.str();
	}
	return s;
}
int main() {
	int N;
	cin >> N;
	
	cout << Sn(N);
}