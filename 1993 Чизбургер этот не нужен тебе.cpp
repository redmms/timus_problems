#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
  cin.sync_with_stdio(false); cin.tie(0);
	string vv;	string f, s, t; string prom;
	getline(cin, vv);
	bool firsttime = true;
	int i = 0;
	while (i < vv.size()) {
		if (vv[i] == '{') {
			i++;
			while (vv[i] != '}') {
				f.push_back(tolower(vv[i]));
				i++;
			}
			if (firsttime) {
				f[0] = toupper(f[0]);
				firsttime = false;
			}
		}
		else if (vv[i] == '(') {
			i++;
			while (vv[i] != ')') {
				s.push_back(tolower(vv[i]));
				i++;
			}
		}
		else if (vv[i] == '[') {
			i++;
			while (vv[i] != ']') {
				t.push_back(tolower(vv[i]));
				i++;
			}
		}
		else if (vv[i] == ',') {
			if (!prom.empty()) cout << prom << ' ';
			cout << f << ' ' << s << ' ' << t << ',' << ' ';
			prom.clear();  f.clear(); s.clear(); t.clear();
			i++;
		}
		else if (vv[i] >= 'a' && vv[i] <= 'z' || vv[i] >= 'A' && vv[i] <= 'Z') {
			prom.push_back(vv[i]);
			i++;
		}
		else
			i++;
	}
	if (!prom.empty()) cout << prom << ' ';
	cout << f << ' ' << s << ' ' << t;
	f.clear(); s.clear(); t.clear();
	i++;
}