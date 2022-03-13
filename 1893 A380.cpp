#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
	string s; int y; char x[2] = {};
	cin >> s;
	y = stoi(s); 
	x[0] = s.back();
	if (1 <= y && y <= 2 && strstr("AD", x) || 3 <= y && y <= 20 && strstr("AF", x) || 21 <= y && y <= 65 && strstr("AK", x))
		cout << "window";
	else if (1 <= y && y <= 2 && strstr("BC", x) || 3 <= y && y <= 20 && strstr("BCDE", x) || 21 <= y && y <= 65 && strstr("CDGH", x))
		cout << "aisle";
	else
		cout << "neither";
}