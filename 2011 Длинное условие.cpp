#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int fac(int n){
    int f = 1, i;
    for (i = 2; i <= n; ++i){
        f = f*i;
    }
    return f;
}
int main() {
    int N;  
    cin >> N;
    string s; 
    cin.ignore();
    getline(cin, s);
    map <int, int> povt; int ndif = 0;
    for (int i = 1; i <= 3; i++) {
        povt[i] = count(s.begin(), s.end(), '0' + i);
        if (povt[i] > 0)
            ndif++;
    }
    if (ndif == 1) {
        cout << "No";
        return 0;
    }
    else if (ndif == 3) {
        cout << "Yes";
        return 0;
    }
    else if (ndif == 2) {
        if (N >= 6) {
            cout << "Yes";
            return 0;
        }
        int ans = fac(N) / (fac(povt[1])*fac(povt[2])*fac(povt[3]));
        if (ans >= 6)
          cout << "Yes";
        else
          cout << "No";
    }
}