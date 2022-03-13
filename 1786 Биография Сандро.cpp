#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int LevenshteinDistance(string s1, string s2){
	int dist = 0;
	for (int i = 0; i < 6; i++) {
		if (s1[i] != s2[i])
			dist++;
	}
	return dist;
}
int main() {
	string goal = "Sandro", inp, subs; map <string, int> longstrdist; int dist, kolZ;
	cin >> inp;
	for (int i = 0; i <= inp.size()-6; i++) {
		subs = inp.substr(i, 6);
		kolZ = 0;
		for (int i1 = 0; i1 < 6; i1++) {
			if (i1 == 0 && islower(subs[0]) && toupper(subs[0]) != goal[0])
				kolZ++;
			else if (i1 != 0 && !islower(subs[i1]) && tolower(subs[i1]) != goal[i1])
				kolZ++;
		}
		longstrdist[subs] = LevenshteinDistance(subs, goal) + kolZ;
	}
	int mindist = 1000;
	for (auto it : longstrdist) {
		if (it.second < mindist)
			mindist = it.second;
	}
	cout << mindist*5;
}