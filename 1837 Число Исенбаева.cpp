#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
int n;
vector <vector <string>> gl(n, vector <string>(3));
queue <string> q;
set <string> used;
map <string, int> d;
void sqn (string str) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 3; j++) 
            if (gl[i][j] == str) {
                if (j == 0) {
                    if (!used.count(gl[i][1])) {
                        q.push(gl[i][1]);
                        d[gl[i][1]] = d[str] + 1;
                        used.insert(gl[i][1]);
                    }

                    if (!used.count(gl[i][2])) {
                        q.push(gl[i][2]);
                        d[gl[i][2]] = d[str] + 1;
                        used.insert(gl[i][2]);
                    }
                }
                if (j == 1) {
                    if (!used.count(gl[i][0])) {
                        q.push(gl[i][0]);
                        d[gl[i][0]] = d[str] + 1;
                        used.insert(gl[i][0]);
                    }
                    if (!used.count(gl[i][2])) {
                        q.push(gl[i][2]);
                        d[gl[i][2]] = d[str] + 1;
                        used.insert(gl[i][2]);
                    }
                }
                if (j == 2) {
                    if (!used.count(gl[i][0])) {
                        q.push(gl[i][0]);
                        d[gl[i][0]] = d[str] + 1;
                        used.insert(gl[i][0]);
                    }

                    if (!used.count(gl[i][1])) {
                        q.push(gl[i][1]);
                        d[gl[i][1]] = d[str] + 1;
                        used.insert(gl[i][1]);
                    }

                }
            }
}//Searches, pushs to the Queue neighbor elements and give Numbers
int main() {
    cin >> n;
    gl.resize(n, vector <string>(3));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 3; j++) 
            cin >> gl[i][j];

    string str;
    q.push("Isenbaev");
    d["Isenbaev"] = 0;
    used.insert("Isenbaev");
    while(!q.empty()) {
        str = q.front();
        q.pop();
        sqn(str);
    }
    bool Ie = false;
    for (int i= 0; i <n;i++)
        for (int j = 0; j < 3; j++) {
            if (!used.count(gl[i][j])) {
                used.insert(gl[i][j]);
                d[gl[i][j]] = -1;
            }
            if (gl[i][j] == "Isenbaev") {
                Ie = true;
            }
        }
    if (Ie == false)
        used.erase("Isenbaev");
    for (auto &it:used) {
        cout << it << " ";
        if (d[it] != -1)
            cout << d[it] << '\n';
        else
            cout << "undefined" << '\n';
    }
}