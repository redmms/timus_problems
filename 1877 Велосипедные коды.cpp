#include <iostream>

using namespace std;

int main() {

	int Code1, Code2;
	
	cin >> Code1 >> Code2;
	if (Code1 % 2 == 0 || Code2 % 2 == 1)
		cout << "yes";
	else cout << "no";

}