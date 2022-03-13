#include <iostream>
#include <string>
#include <map>
#include <regex>
using namespace std;
map<string, int>mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	string tr = "tram";
	string tro = "trolleybus";
	string last = "";
	while (getline(cin, s)) {
		string subject = s;
		regex re("\\w+");
		sregex_iterator next(subject.begin(), subject.end(), re);
		sregex_iterator end;
		while (next != end) {
			smatch match = *next;
			last = match.str();
			if (last == tr)
				mp[tr]++;
			else if (last == tro)
				mp[tro]++;
			next++;
		}


	}
	if (mp[tro]>mp[tr])
		cout << "Trolleybus driver" << endl;
	else if (mp[tr]>mp[tro])
		cout << "Tram driver" << endl;
	else
		cout << "Bus driver" << endl;
}