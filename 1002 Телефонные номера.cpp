#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator> 
#include <deque>
using namespace std;
int minl, numbs;
struct my_greater {
	bool operator () (string const &a, string const &b) const { return a.size() != b.size() ? a.size() > b.size() : a > b; }
}; 
int rec(string & numb, int pos, map <int, set <string, my_greater>> & ind, deque <string> & ans, int length) {
	length++;
	if (pos == numbs && length < minl) {
		ans.clear();
		minl = length;
		return -1;
	}
	else if (pos > numbs || length >= minl || ind.find(pos) == ind.end())
		return -2;
	int ret = -2;
	for (auto it = ind[pos].begin(); it != ind[pos].end(); it++) {
		int REC = rec(numb, pos + it->size(), ind, ans, length);
		if (REC == -1) {
			ans.push_back(*it);
			ret = -1;
		}
	}
	return ret;
}
int main() {
	cin.sync_with_stdio(false); cin.tie(0);
    map <char, string> table = { {'0', "oqz"}, {'1', "ij"}, {'2', "abc"}, {'3', "def"}, {'4', "gh"}, {'5', "kl"}, {'6', "mn"}, {'7', "prs"}, {'8', "tuv"}, {'9', "wxy"}};
	string numb; int n;
    while (cin >> numb && numb != "-1") {
        cin >> n;
        map <string, string> eqv;  string s;
        for (int in = 1; in <= n; in++) {
            cin >> s;
			string converted;
			for (int i = 0; i < s.size(); i++) {
				for (char itbl = '0'; itbl <= '9'; itbl++) {
					if (find(table[itbl].begin(), table[itbl].end(), s[i]) != table[itbl].end())
						converted.push_back(itbl);
				}
			}
            eqv[converted] = s;
        }
		map<int, set <string, my_greater>> ind;
		for (auto eqel = eqv.begin(); eqel != eqv.end() && !eqv.empty();) {
			auto eqf = eqel->first;	auto found = numb.find(eqf);
			if (found == string::npos) {
				eqel++;
				eqv.erase(eqf);
			}
			else {
				do {
					ind[found].insert(eqf);
					found = numb.find(eqf, ++found);
				} 
				while (found != string::npos);
				eqel++;
			}
		}
		deque <string> ans; minl = INT_MAX, numbs = numb.size();
		rec(numb, 0, ind, ans, 0);
		if (ans.empty()) 
			cout << "No solution." << '\n';
		else {
			while (!ans.empty()) {
				cout << eqv[ans.back()] << ' ';
				ans.pop_back();
			}
			cout << '\n';
		}
    }
}