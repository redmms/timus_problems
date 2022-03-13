#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector <string> c = { "AliceArielAuroraPhilPeterOlafPhoebusRalphRobin","BambiBelleBoltMulanMowgliMickeySilverSimbaStitch", "DumboGenieJiminyKuzkoKidaKenaiTarzanTianaWinnie" };
//c-cupboard

int search(string name) {
	int i = 0;
	for (i = 0; i < 2; i++) {
		if (c[i].find(name) != string::npos)
			break;
	}
	return i;
}
int main() {
	int i, n;

	cin >> n;
	string name;
	int ans = 0;
	int cPred = 0;
	int cNow;
	for (i = 0; i < n; i++) {
		cin >> name;
		cNow = search(name);
		ans += abs(cNow - cPred);
		cPred = cNow;
	}

	cout << ans;
}
