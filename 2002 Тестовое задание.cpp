#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
int main() {
	int n;
	cin >> n;

	string command, username, password; vector <string> names, passwords; vector <int> IsLogin(n); fill(IsLogin.begin(), IsLogin.end(), 0);
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "register") {
			cin >> username >> password;
			if (find(names.begin(), names.end(), username) == names.end()) {
				names.push_back(username);
				passwords.push_back(password);
				cout << "success: new user added" << '\n';
			}
			else
				cout << "fail: user already exists" << '\n';
		}
		if (command == "login"){
			cin >> username >> password;
			auto f = find(names.begin(), names.end(), username);
			if (f == names.end())
				cout << "fail: no such user" << '\n';
			else if (passwords[f - names.begin()] != password)
				cout << "fail: incorrect password" << '\n';
			else if (IsLogin[f - names.begin()] == 1)
				cout << "fail: already logged in" << '\n';
			else {
				IsLogin[f - names.begin()] = 1;
				cout << "success: user logged in" << '\n';
			}
		}
		if (command == "logout") {
			cin >> username;
			auto f = find(names.begin(), names.end(), username);
			if (f == names.end())
				cout << "fail: no such user" << '\n';
			else if (IsLogin[f - names.begin()] == 0)
				cout << "fail: already logged out" << '\n';
			else {
				IsLogin[f - names.begin()] = 0;
				cout << "success: user logged out" << '\n';
			}
		}
	}
}