#include <iostream>
using namespace std;
int main() {
    int n, inK, N = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inK;
        N += (inK - 1) / 2;
    }
    if (N % 2 == 1)
        cout << "Daenerys";
    else
        cout << "Stannis";
}