#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string s; int N, E = 0, M = 0, L = 0;

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		if (s == "Emperor Penguin")
			E++;
		if (s == "Macaroni Penguin")
			M++;
		if (s == "Little Penguin")
			L++;
	}
	int MAX = max(E, max(M, L));
	if (MAX == E)
		cout << "Emperor Penguin";
	else if (MAX == M)
		cout << "Macaroni Penguin";
	else if (MAX == L)
		cout << "Little Penguin";
}